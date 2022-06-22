#include <bits/stdc++.h>

using namespace std;

int t;

bool dose_match(char l, char r) {
    return l == '(' && r == ')';
}

bool is_vps(const string &str) {
    stack<char> s;
    for (char c: str) {
        if (s.empty() ||!dose_match(s.top(), c)) {
            s.push(c);
        } else {
            s.pop();
        }
    }

    return s.empty();
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    string str;
    for (auto i = 0; i < t; ++i) {
        cin >> str;
        is_vps(str) ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}