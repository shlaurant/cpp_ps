#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m, k;
vector<ll> seq;
vector<ll> bit;

void update(int index, ll val) {
    ++index;
    while (index <= n) {
        bit[index] += val;
        index += index & (-index);
    }
}

void make_bit() {
    bit.resize(n + 1);
    for (auto i = 0; i < n; ++i) {
        update(i, seq[i]);
    }
}

ll sum_of(int index) {
    ++index;

    ll ret = 0;
    while (index > 0) {
        ret += bit[index];
        index -= index & (-index);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    seq.resize(n);
    for (auto &el: seq) {
        cin >> el;
    }

    make_bit();

    long long a, b, c;
    for (auto i = 0; i < m + k; ++i) {
        cin >> a >> b >> c;
        if (a == 1) {
            auto diff = c - seq[b - 1];
            seq[b - 1] = c;
            update(b - 1, diff);
        } else {
            cout << sum_of(c - 1) - sum_of(b - 2) << '\n';
        }
    }

    return 0;
}