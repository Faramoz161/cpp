#include <iostream>
#include <atomic>

#include "my_thread.h"

using namespace std;

int main() {
    atomic<int> i = 0;
    
    my_thread t1([&i] () {
        for (int a = 0; a < 10000; a++)
            i++;
        return 0;
    });
    
    my_thread t2([] () { return 0; });
    
    t1.join();
    t2.join();
    cout << i << endl;
    return 0;
}