//2058
#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> dist;

vector<vector<int>> dp;

int look_up(int city, int track) {
    if (dp[city][track] != -1) return dp[city][track];
    if (city == 0 && track == (1 << n) - 1) return 0;

    int val = 16 * 1e6 + 1;
    for (auto nc = 0; nc < n; ++nc) {
        if (track & (1 << nc)) continue;
        if (dist[city][nc] == 0) continue;
        val = min(val, look_up(nc, track | (1 << nc)) + dist[city][nc]);
    }
    dp[city][track] = val;
    return dp[city][track];
}

int sol() {
    dp.resize(n, vector<int>(1 << n, -1));
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