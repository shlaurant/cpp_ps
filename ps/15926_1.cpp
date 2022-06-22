#include <bits/stdc++.h>

using namespace std;

string str;

int main() {
    int n, ret = 0;
    stack<int> s;
    cin >> n;
    cin >> str;
    s.push(-1);
    for (int i = 0; i < n; i++) {
        if (str[i] == '(') s.push(i);
        if (str[i] == ')') {
            s.pop();
            if (!s.empty()) {
                ret = max(ret, i - s.top());
            } else {
                s.push(i);
            }
        }
    }
    cout << ret << '\n';

    return 0;
}