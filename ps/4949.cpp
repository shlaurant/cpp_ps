#include <bits/stdc++.h>

using namespace std;

bool does_match(char l, char r) {
    return (l == '(' && r == ')') || (l == '[' && r == ']');
}

bool is_good(const string &str) {
    stack<char> s;
    for (char c: str) {
        if (c == ')' || c == ']') {
            if (s.empty()) return false;
            if (does_match(s.top(), c)) {
                s.pop();
            } else {
                return false;
            }
        } else if (c == '(' || c == '[') {
            s.push(c);
        }
    }
    if (s.empty()) {
        return true;
    } else {
        return false;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    while (getline(cin, str)) {
        if (str == ".") {
            return 0;
        }
        is_good(str) ? cout << "yes\n" : cout << "no\n";
    }

    return 0;
}