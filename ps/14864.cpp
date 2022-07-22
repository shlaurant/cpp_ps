#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> prev_cnt;
vector<int> num;
vector<pair<int, int>> check;

vector<int> bit;

vector<int> ans;

bool is_ok() {
    for (const auto &el: check) {
        if (ans[el.first] < ans[el.second]) return false;
    }
    return true;
}

void update(int index, int val) {
    index += 1;
    while (index <= n) {
        bit[index] += val;
        index += index & (-index);
    }
}

void cons_bit() {
    bit.resize(n + 1);
    for (auto i = 0; i < n; ++i) {
        update(i, 1);
    }
}

int query(int index) {
    index += 1;
    int ret = 0;
    while (index > 0) {
        ret += bit[index];
        index -= index & (-index);
    }
    return ret;
}

int bs(int cnt) {
    if (cnt == 0 && query(0) == 1) return 0;
    int l = 1, r = n;
    while (l < r) {
        auto mid = (l + r) / 2;
        int val = query(mid - 1);
        if (val == cnt) return mid;
        else if (val > cnt) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}

bool sol() {
    num.resize(n);
    for (auto i = 0; i < n; ++i) {
        num[i] = i + 1;
    }

    cons_bit();

    for (auto el: prev_cnt) {
        auto index = bs(el);
        if (index == -1) return false;
        ans.push_back(num[index]);
        update(index, -1);
    }

    return is_ok();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    prev_cnt.resize(n);
    for (auto i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        ++prev_cnt[--a];
        check.push_back({a, --b});
    }

    if (sol()) {
        for (auto el: ans) {
            cout << el << ' ';
        }
    } else cout << -1;

    return 0;
}