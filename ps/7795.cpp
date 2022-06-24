#include <bits/stdc++.h>

using namespace std;

int t, n, m;
vector<int> a, b;

int sol() {
    int ret = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    auto ia = a.begin();
    auto ib = b.begin();

    int cnt = 0;
    while (ia != a.end() && ib != b.end()) {
        while (*ia > *ib && ib != b.end()) {
            ++cnt;
            ++ib;
        }
        ret += cnt;
        ++ia;
    }

    while (ia != a.end()) {
        ret += cnt;
        ++ia;
    }

    return ret;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    for (auto i = 0; i < t; ++i) {
        cin >> n >> m;
        a.resize(n);
        b.resize(m);
        for (auto &el: a) {
            cin >> el;
        }
        for (auto &el: b) {
            cin >> el;
        }
        cout << sol() << '\n';
    }

    return 0;
}