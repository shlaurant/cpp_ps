#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m, k;
vector<ll> seq;

vector<ll> st;

void const_st() {
    st.resize(seq.size() * 2);
    copy(seq.begin(), seq.end(), st.begin() + seq.size());
    for (auto i = n - 1; i > 0; --i) {
        st[i] = st[i << 1] + st[i << 1 | 1];
    }
}

void update(int index, ll val) {
    index += n;
    st[index] = val;
    while ((index >> 1) > 0) {
        st[index >> 1] = st[index] + st[index ^ 1];
        index >>= 1;
    }
}

ll get(int l, int r) {
    ll ret = 0;
    l += n;
    r += n;
    while (l < r) {
        if (l & 1) ret += st[l++];
        if (r & 1) ret += st[--r];
        l >>= 1;
        r >>= 1;
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

    const_st();

    ll a, b, c;
    for (auto i = 0; i < m + k; ++i) {
        cin >> a >> b >> c;
        if (a == 1) {
            update(b - 1, c);
        } else {
            cout << get(b - 1, c) << '\n';
        }
    }


    return 0;
}