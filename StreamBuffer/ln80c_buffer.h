#include <iostream>
#include <string>

using namespace std;

class ln80c_buffer : public streambuf {
private:
    streambuf* buffer;
    size_t line_number;
    size_t line_size;
    bool is_newStr;

public:
    ln80c_buffer(std::streambuf* b) : buffer(b), line_number(1), line_size(0), is_newStr(true) { }

protected:
    int_type overflow(int_type c) override {
        if(is_newStr) {
            string str = to_string(line_number++);
            if(str.size() < 8)
                str += string(8 - str.size(), ' ');

            buffer->sputn(str.data(), 8);
            is_newStr = false;
            line_size = 0;
        }

        is_newStr = line_size == 71 || (char)c == '\n';
        buffer->sputc(c);
        if(line_size == 71)
            buffer->sputc('\n');
        ++line_size;
        return c;
    }
};