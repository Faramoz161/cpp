#pragma once

#include <ostream>

using namespace std;

template<typename T>
class ostream_iter {
private:
    ostream* _ostream;
    const char* _delimetr;
    const size_t _items_in_line;
    size_t _current;

public:
    ostream_iter(ostream& stream, const char* delimetr, const size_t items_in_line) : _ostream(&stream), _delimetr(delimetr), _items_in_line(items_in_line), _current(0) { }

    ostream_iter& operator=(const T& value) {
        if(_current % N == 0) {
            *_ostream << value;
            if(_delimetr) 
                *_ostream << _delimetr;
        }
        _current++;
        return *this;
    }

    ostream_iter& operator*() { return *this; }
    ostream_iter& operator++() { return *this; }
    ostream_iter& operator++(int) { return *this; }
};

namespace std {
    template<typename T>
    struct iterator_traits<ostream_iter<T>> {
        using iterator_category = std::output_iterator_tag;
        using value_type = void;
        using difference_type = void;
        using pointer = void;
        using reference = void;
    };
}
