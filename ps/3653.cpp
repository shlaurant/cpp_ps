#include <bits/stdc++.h>

using namespace std;

int t, n, m;
vector<int> seq;

vector<int> st;

void cons_st() {
    st.resize(2 * (n + m));
    fill(st.begin(), st.end(), 0);
    for (auto i = n + m + m; i < 2 * (n + m); ++i) {
        st[i] = 1;
    }
    for (auto i = n + m - 1; i > 0; --i) {
        st[i] = st[i << 1] + st[i << 1 | 1];
    }
}

int get(int l, int r) {
    int ret = 0;
    l += n + m;
    r += n + m;
    while (l < r) {
        if (l & 1) ret += st[l++];
        if (r & 1) ret += st[--r];
        l >>= 1;
        r >>= 1;
    }
    return ret;
}

void update(int index, int val) {
    index += n + m;
    st[index] = val;
    while ((index >> 1) > 0) {
        st[index >> 1] = st[index] + st[index ^ 1];
        index >>= 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    for (auto i = 0; i < t; ++i) {
        cin >> n >> m;
        seq.resize(n + 1);
        for (auto j = 1; j <= n; ++j) {
            seq[j] = m + j - 1;
        }
        cons_st();
        int a;
        for (auto j = 0; j < m; ++j) {
            cin >> a;
            cout << get(0, seq[a]) << ' ';
            update(seq[a], 0);
            seq[a] = m - 1 - j;
            update(seq[a], 1);
        }
        cout << '\n';
    }

    return 0;
}