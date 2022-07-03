#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> dist;

vector<vector<int>> dp;

int look_up(int city, int visit) {
    if (dp[city][visit] != -1) return dp[city][visit];

    int val = 16e6 + 1;
    for (auto i = 0; i < n; ++i) {
        if (!(visit & (1 << i)) && dist[city][i] != 0) {
            val = min(val, look_up(i, visit | (1 << i)) + dist[city][i]);
        }
    }
    dp[city][visit] = val;
    return dp[city][visit];
}

int sol() {
    dp.resize(n, vector<int>(1 << n, -1));
    dp[0][(1 << n) - 1] = 0;
    return look_up(0, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    dist.resize(n, vector<int>(n));
    for (auto &rw: dist) {
        for (auto &el: rw) {
            cin >> el;
        }
    }

    cout << sol();

    return 0;
}