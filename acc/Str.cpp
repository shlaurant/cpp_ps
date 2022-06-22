//
// Created by shkla on 2022-06-09.
//

#include "Str.h"

typedef Str::size_type size_type;

Str &Str::operator+=(const Str &s) {
    std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
    return *this;
}

Str operator+(const Str &l, const Str &r) {
    Str ret = l;
    return ret += r;
}

std::istream &operator>>(std::istream &is, Str &str) {
    str.data.clear();
    char c;

    while (is.get(c) && isspace(c));

    if (is) {
        do str.data.push_back(c);
        while (is.get(c) && !isspace(c));
        if (is) is.unget();
    }
}

std::ostream &operator<<(std::ostream &os, const Str &str) {
    for (size_type i = 0; i < str.size(); ++i) {
        os << str[i];
    }
    return os;
}
