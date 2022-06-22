#include <bits/stdc++.h>

using namespace std;

int sz, m, n;
vector<int> a, b;

vector<int> ca, cb;
map<int, int> ma, mb;

void make_cvecs() {
    ca.resize(2 * m);
    ca.front() = a.front();
    for (auto i = 1; i < 2 * m; ++i) {
        ca[i] = ca[i - 1] + a[i % m];
    }

    cb.resize(2 * n);
    cb.front() = b.front();
    for (auto i = 1; i < 2 * n; ++i) {
        cb[i] = cb[i - 1] + b[i % n];
    }
}

void _regi(vector<int> &cv, map<int, int> &mp, int cnt) {
    mp[0] = 1;
    mp[cv[cnt - 1]] = 1;
    for (auto i = 0; i < cnt; ++i) {
        for (auto j = 0; j < cnt - 1; ++j) {
            if (i - 1 == -1) {
                ++mp[cv[i + j]];
            } else {
                ++mp[cv[i + j] - cv[i - 1]];
            }
        }
    }
}

void regi_mps() {
    _regi(ca, ma, m);
    _regi(cb, mb, n);
}

int sol() {
    int ret = 0;

    make_cvecs();
    regi_mps();
    for (const auto &el: ma) {
        if (sz >= el.first) {
            ret += el.second * mb[sz - el.first];
        }
    }

    return ret;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> sz;
    cin >> m >> n;

    a.resize(m);
    b.resize(n);
    for (auto &el: a) {
        cin >> el;
    }
    for (auto &el: b) {
        cin >> el;
    }

    cout << sol();

    return 0;
}