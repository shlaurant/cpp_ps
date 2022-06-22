#ifndef ACCCPP_2DARR_H
#define ACCCPP_2DARR_H

#include <string>

template<size_t r, size_t c>
std::string stringfy(int (&arr)[r][c], int rl = r, int cl = c) {
    std::string ret;

    for (auto i = 0; i < rl; ++i) {
        for (auto j = 0; j < cl; ++j) {
            ret += std::to_string(arr[i][j]);
            if (j != cl - 1) ret += ' ';
        }
        ret += '\n';
    }
    return ret;
}

#endif //ACCCPP_2DARR_H
