#include <bits/stdc++.h>

using namespace std;

int t;
int n, m;
vector<int> a, b;

map<int, int> acnt;
map<int, int> bcnt;


void _count(const vector<int> &vec, map<int, int> &mp) {
    auto v = vector<int>(vec);
    copy(vec.begin(), vec.end(), back_inserter(v));
    for (auto i = 1; i < 2 * vec.size(); ++i) {
        v[i] += v[i - 1];
    }

    for (auto sz = 1; sz < vec.size(); ++sz) {
        for (auto i = 0; i < vec.size(); ++i) {
            if (i > 0) ++mp[v[i + sz - 1] - v[i - 1]];
            else ++mp[v[i + sz - 1]];
        }
    }
    ++mp[v[vec.size() - 1]];
    mp[0] = 1;
}

long long sol() {
    long long ret = 0;

    _count(a, acnt);
    _count(b, bcnt);

    for (const auto &el: acnt) {
        ret += el.second * bcnt[t - el.first];
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    cin >> n;
    cin >> m;
    a.resize(n);
    b.resize(m);
    for (auto &el: a) {
        cin >> el;
    }
    for (auto &el: b) {
        cin >> el;
    }

    cout << sol();

    return 0;
}