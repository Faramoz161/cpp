#include <iostream>
#include <string>
#include <ostream>
#include <sstream>

#include "start_buffer.h"
#include "ln80c_buffer.h"

using namespace std;

int main() {
    stringbuf str_buffer;
    ln80c_buffer buffer = ln80c_buffer(&str_buffer);
    ostream stream(&buffer);

    stream << "asd asdqw sd\n" + string(75, 'a');
    cout << str_buffer.str() << endl;

    streambuf* old_buffer = cin.rdbuf();
    stat_buffer stat_buffer(old_buffer);
    cin.rdbuf(&stat_buffer);

    cout << cin.rdbuf();
    cout << stat_buffer.getStrCount() << " " << stat_buffer.getWordCount() << " " << stat_buffer.getCharCount() << endl;
    cin.rdbuf(old_buffer);

    return 0;
}