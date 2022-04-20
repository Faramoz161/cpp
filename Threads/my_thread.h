#pragma once

#include <sched.h>
#include <sys/wait.h>
#include <signal.h>

#include <functional>
#include <system_error>

using namespace std;

#define CHECK(func) if ((func) == -1) throw system_error(errno, generic_category());

template<typename Function>
static int wrapper(void* ptr) {
    Function* fun = reinterpret_cast<Function*>(ptr);
    int ret;
    try {
        ret = (*fun)();
    } catch (...) {
        ret = 1;
    }
    return ret;
}

class my_thread {
private:
    const size_t stack_size = 1024*1024;
    pid_t pid;
    char* stack;

public:
    my_thread() = default;
    my_thread(const my_thread&) = delete;

    template<class Function>
    explicit my_thread(Function& f) {
        stack = new char[stack_size];
        CHECK(pid = clone(wrapper<Function>, stack + stack_size, CLONE_VM | SIGCLD, &f));
    }

    my_thread(my_thread&& other) : pid(other.pid), stack(std::move(other.stack)) {
        other.pid = 0;
    }

    my_thread& operator=(my_thread&& other) {
        this->swap(other);
        return *this;
    }

    pid_t get_id() { return pid; }

    bool joinable() {
        return pid != 0 && kill(pid, 0) == 0;
    }

    void join() {
        int status;
        CHECK(waitpid(pid, &status, 0));
    }

    void swap(my_thread& other) {
        std::swap(this->pid, other.pid);
        std::swap(this->stack, other.stack);
    }

    ~my_thread() {
        if (pid != 0) {
            kill(pid, SIGTERM);
            delete[] stack;
        }
    }
};
