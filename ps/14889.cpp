#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> s;

int sum_of(int i, int j) {
    int ret = 0;

    for (auto k = 0; k < n; ++k) {
        if ((bool) (i & 1 << j) == (bool) (i & 1 << k)) ret += s[j][k];
    }

    return ret;
}

void dfs(int i, int j, int cnt, int &ret) {
    if (cnt == n / 2) {
        int sum0 = 0, sum1 = 0;
        for (auto k = 0; k < n; ++k) {
            i & 1 << k ? sum1 += sum_of(i, k) : sum0 += sum_of(i, k);
        }
        ret = min(ret, abs(sum0 - sum1));
        return;
    }
    if (j >= n) return;
    dfs(i | 1 << j, j + 1, cnt + 1, ret);
    dfs(i, j + 1, cnt, ret);
}

int sol() {
    int ret = INT_MAX;

    dfs(0, 0, 0, ret);

    return ret;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    s.resize(n, vector<int>(n));
    for (auto &rw: s) {
        for (auto &el: rw) {
            cin >> el;
        }
    }

    cout << sol();

    return 0;
}