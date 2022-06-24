#include <bits/stdc++.h>

using namespace std;

int ca, cb;
vector<int> a, b;

bool check(const vector<int> &vec, int v) {
    auto it = lower_bound(vec.begin(), vec.end(), v);
    return !(it == vec.end()) && *it == v;
}

int cnt_l_r(const vector<int> &l, const vector<int> &r) {
    int ret = 0;

    auto it = l.begin();
    while (it != l.end()) {
        if (it == l.begin() || *it != *(it - 1)) {
            if (!check(r, *it)) ++ret;
        }
        ++it;
    }

    return ret;
}

int sol() {
    int ret = 0;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ret += cnt_l_r(a, b);
    ret += cnt_l_r(b, a);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> ca >> cb;
    a.resize(ca);
    b.resize(cb);
    for (auto &el: a) {
        cin >> el;
    }
    for (auto &el: b) {
        cin >> el;
    }

    cout << sol();

    return 0;
}