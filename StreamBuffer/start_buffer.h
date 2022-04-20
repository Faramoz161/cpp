#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class stat_buffer : public streambuf {
private:
    streambuf* buffer;
    size_t line_count;
    size_t word_count;
    size_t char_count;
    bool is_prev_delimetr;

public:
    stat_buffer(streambuf* b) : buffer(b), line_count(0), word_count(0), char_count(0), is_prev_delimetr(true) { }

    int getStrCount() { return line_count; }
    int getWordCount() { return word_count; }
    int getCharCount() { return char_count; }

protected:
    int_type underflow() override {
        int_type c = buffer->sbumpc();
        if(c == traits_type::eof())
            return c;

        if(isalpha(c) || isdigit(c)) {
            if(is_prev_delimetr) {
                word_count++;
                is_prev_delimetr = false;
            }
        } else
            is_prev_delimetr = true;

        if(c == '\n')
            line_count++;
        char_count++;

        char ch = traits_type::to_char_type(c);
        setg(&ch, &ch, &ch + 1);
        return c;
    }
};