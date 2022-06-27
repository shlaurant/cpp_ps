#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m, k;
vector<ll> seq;
vector<ll> st;

void make_st() {
    st.resize(2 * n);
    for (auto i = 0; i < n; ++i) {
        st[n + i] = seq[i];
    }

    for (auto i = n - 1; i > 0; --i) {
        st[i] = st[i << 1] + st[i << 1 | 1];
    }
}

void update(int index, ll val) {
    index += n;
    st[index] = val;
    while (index > 1) {
        st[index >> 1] = st[index] + st[index ^ 1];
        index >>= 1;
    }
}

ll query(int l, int r) {
    ll ret = 0ll;

    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret += st[l++];
        if (r & 1) ret += st[--r];
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

    make_st();

    long long a, b, c;
    for (auto i = 0; i < m + k; ++i) {
        cin >> a >> b >> c;
        if (a == 1) {
            seq[b - 1] = c;
            update(b - 1, c);
        } else {
            cout << query(b-1, c) << '\n';
        }
    }

    return 0;
}