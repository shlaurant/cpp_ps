#include <bits/stdc++.h>

using namespace std;

int t, n;
vector<pair<int, int>> coord;

vector<int> yc;
vector<int> st;

void cons_st() {
    st.resize(2 * n);
    fill(st.begin(), st.end(), 0);
}

int query(int l, int r) {
    int ret = 0;
    l += n;
    r += n;
    while (l < r) {
        if (l & 1) ret += st[l++];
        if (r & 1) ret += st[--r];
        r >>= 1;
        l >>= 1;
    }
    return ret;
}

int _y(int y) {
    int l = 0, r = n;
    while (l < r) {
        auto mid = (l + r) / 2;
        if (yc[mid] == y) return mid;
        else if (yc[mid] > y) r = mid;
        else l = mid + 1;
    }
    throw domain_error("??");
}

void update(int index) {
    index += n;
    st[index] += 1;
    while (index > 1) {
        st[index >> 1] = st[index] + st[index ^ 1];
        index >>= 1;
    }
}

long long sol() {
    long long ret = 0;
    cons_st();

    reverse(coord.begin(), coord.end());
    for (const auto &el: coord) {
        ret += query(_y(el.second), yc.size());
        update(_y(el.second));
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
        coord.resize(n);
        yc.clear();
        for (auto &el: coord) {
            cin >> el.first >> el.second;
            el.second = -el.second;
            yc.push_back(el.second);
        }
        sort(coord.begin(), coord.end());
        sort(yc.begin(), yc.end());
        cout << sol() << '\n';
    }

    return 0;
}