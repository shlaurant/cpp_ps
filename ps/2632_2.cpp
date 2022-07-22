#include <bits/stdc++.h>

using namespace std;

int sz, m, n;
vector<int> a, b;
map<int, int> ma, mb;

void make_m(const vector<int> &v, map<int, int> &mp) {
    auto tv = vector<int>(v);
    copy(v.begin(), v.end(), back_inserter(tv));
    for (auto i = 1; i < tv.size(); ++i) {
        tv[i] += tv[i - 1];
    }
    tv.insert(tv.begin(), 0);
    for (auto s = 1; s < v.size(); ++s) {
        for (auto i = 0; i < v.size(); ++i) {
            ++mp[tv[i + s] - tv[i]];
        }
    }
    mp[0] = 1;
    mp[tv[v.size()]] = 1;
}

long long sol() {
    long long ret = 0;

    make_m(a, ma);
    make_m(b, mb);

    for (auto el: ma) {
        ret += (long long) mb[sz - el.first] * el.second;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> sz >> m >> n;
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