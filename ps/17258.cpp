#include <bits/stdc++.h>

using namespace std;

int n, m, k, t;
vector<int> pop;

vector<vector<vector<int>>> dp;

int look_up(int time, int left, int roll) {
    if (time > n) return 0;
    if (dp[time][left][roll] != -1) return dp[time][left][roll];

    int val = 0;
    if (pop[time] + roll >= t) {
        if (pop[time] >= t) roll = 0;
        val = max(val, look_up(time + 1, left, roll) + 1);
    } else {
        val = max(val, look_up(time + 1, left, roll));
        auto temp = t - pop[time] - roll;
        if (temp <= left) {
            val = max(val, look_up(time + 1, left - temp, roll + temp) + 1);
        }
    }

    dp[time][left][roll] = val;
    return dp[time][left][roll];
}

int sol() {
    dp.resize(n + 1, vector<vector<int>>(k + 1, vector<int>(k + 1, -1)));
    return look_up(1, k, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k >> t;
    pop.resize(n + 1);
    for (auto i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        for (auto j = a; j < b; ++j) {
            ++pop[j];
        }
    }

    cout << sol();

    return 0;
}