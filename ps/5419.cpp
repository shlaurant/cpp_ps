#include <bits/stdc++.h>

using namespace std;

int t, n;
vector<pair<int, int>> iv;
vector<int> y;

vector<int> st;

void cons_st() {
    st = vector<int>(n * 2);
}

int query(int l, int r) {
    int ret = 0;

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

void update(int index, int val) {
    index += n;
    st[index] += val;
    while (index > 1) {
        st[index >> 1] = st[index] + st[index ^ 1];
        index >>= 1;
    }
}

int index_of(int yv) {
    int l = 0, r = n;
    while (l < r) {
        auto mid = (l + r) / 2;
        if (y[mid] == yv) {
            return mid;
        } else if (y[mid] > yv) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
}

long long sol() {
    long long ret = 0;

    sort(iv.begin(), iv.end());
    sort(y.begin(), y.end());
    cons_st();

    for (auto i = n - 1; i >= 0; --i) {
        auto index = index_of(iv[i].second);
        ret += query(index, n);
        update(index, 1);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    for (auto i = 0; i < t; ++i) {
        cin >> n;
        iv.resize(n);
        y.clear();
        for (auto &el: iv) {
            cin >> el.first >> el.second;
            el.second *= -1;
            y.push_back(el.second);
        }
        cout << sol() << '\n';
    }

    return 0;
}