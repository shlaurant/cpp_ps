#include <bits/stdc++.h>

using namespace std;

struct info {
    int wt, wp, bt, bp;
};

int n, k;
vector<info> iv;

vector<vector<int>> dp;

int look_up(int node, int time) {
    if (dp[node][time] != -1) return dp[node][time];
    if (node == n) {
        return time >= 0 ? 0 : INT_MIN;
    }

    int val = INT_MIN;
    if (time - iv[node].wt >= 0) {
        val = max(val, look_up(node + 1, time - iv[node].wt) + iv[node].wp);
    }

    if (time - iv[node].bt >= 0) {
        val = max(val, look_up(node + 1, time - iv[node].bt) + iv[node].bp);
    }

    dp[node][time] = val;
    return dp[node][time];
}

int sol() {
    dp.resize(n + 1, vector<int>(k + 1, -1));

    return look_up(0, k);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    iv.resize(n);
    for (auto &el: iv) {
        cin >> el.wt >> el.wp >> el.bt >> el.bp;
    }

    cout << sol();

    return 0;
}