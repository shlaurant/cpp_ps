#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using std::vector;
using std::string;

bool is_space(char c) {
    return std::isspace(c);
}

bool is_not_space(char c) {
    return !is_space(c);
}

vector<string> split(const string &str) {
    vector<string> ret;

    string::const_iterator iter_begin = str.begin();
    string::const_iterator iter_end;

    while (iter_begin != str.end()) {
        iter_begin = std::find_if(iter_begin, str.end(), is_not_space);
        iter_end = std::find_if(iter_begin, str.end(), is_space);
        if(iter_begin != str.end()){
            ret.push_back(string(iter_begin, iter_end));
        }

        return ret;
    }

    return ret;
}