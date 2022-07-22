#include <bits/stdc++.h>

using namespace std;

int n, c;
vector<int> w;

vector<int> l, r;

void make_sv(int b, int e, vector<int> &v) {
    for (auto i = 0; i < (1 << e - b); ++i) {
        long long sum = 0;
        for (auto j = 0; j < e - b; ++j) {
            if (i & 1 << j) sum += w[j + b];
            if (sum > c) continue;
        }
        if (sum <= c) v.push_back(sum);
    }
}

int sol() {
    int ret = 0;

    make_sv(0, n / 2, l);
    make_sv(n / 2, n, r);

    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

    for (auto el: l) {
        ret += upper_bound(r.begin(), r.end(), c - el) - r.begin();
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> c;
    w.resize(n);
    for (auto &el: w) {
        cin >> el;
    }

    cout << sol();

    return 0;
}