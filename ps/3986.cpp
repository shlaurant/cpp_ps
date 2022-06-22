#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int ret = 0;

    for (auto i = 0; i < n; ++i) {
        stack<char> s;
        string str;
        cin >> str;
        for (const char &c: str) {
            if (!s.empty() && s.top() == c) {
                s.pop();
            } else {
                s.push(c);
            }
        }
        if (s.empty()) {
            ++ret;
        }
    }

    cout << ret;
}