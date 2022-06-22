#include <bits/stdc++.h>

using namespace std;

int n, m, cur;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    m = 0;
    for (cur = 666; m < n; ++cur) {
        auto str = to_string(cur);
        if (str.find("666") != string::npos) {
            ++m;
        }
    }

    cout << --cur;
    return 0;
}