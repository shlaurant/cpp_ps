//2051
#include <bits/stdc++.h>

using namespace std;

void iter(stack<char> &s, const string &str) {
    for (auto el: str) {
        if (s.empty()) {
            s.push(el);
        } else if (s.top() == el) {
            s.pop();
        } else {
            s.push(el);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ret = 0;
    int c;
    cin >> c;
    for (auto i = 0; i < c; ++i) {
        stack<char> s;
        string str;
        cin >> str;
        iter(s, str);
        if (s.empty()) ++ret;
    }

    cout << ret;

    return 0;
}