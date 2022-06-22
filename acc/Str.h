//
// Created by shkla on 2022-06-09.
//

#ifndef ACCCPP_STR_H
#define ACCCPP_STR_H


#include <cstring>
#include <iostream>
#include "Vec.h"

class Str {
public:
    typedef Vec<char>::size_type size_type;

    Str() {}

    Str(size_type n, char c) : data(n, c) {}

    Str(const char *cp) {
        std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));
    }

    template<class In>
    Str(In b, In e) {
        std::copy(b, e, std::back_inserter(data));
    }

    size_type size() const { return data.size(); }

    char &operator[](size_type i) { return data[i]; }
    const char &operator[](size_type i) const { return data[i]; }

    friend std::istream &operator>>(std::istream&, Str&);
    Str &operator+=(const Str &);

private:
    Vec<char> data;
};

std::istream &operator>>(std::istream &, Str &);
std::ostream &operator<<(std::ostream &, const Str &);

Str operator+(const Str &a, const Str &b);


#endif //ACCCPP_STR_H
