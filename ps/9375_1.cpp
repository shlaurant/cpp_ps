#include "bits/stdc++.h"

using namespace std;

int t;

int sol(int cnt, const map<string, int> &m) {
    int ret = 1;

    auto it = m.begin();

    while (it != m.end()) {
        ret *= it->second + 1;
        ++it;
    }

    return ret - 1;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    int n;
    string cloth, type;
    map<string, int> m;

    for (auto i = 0; i < t; ++i) {
        m.clear();
        cin >> n;
        for (auto j = 0; j < n; ++j) {
            cin >> cloth >> type;
            ++m[type];
        }
        cout << sol(n, m) << '\n';
    }

    return 0;
}