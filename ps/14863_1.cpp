#include <bits/stdc++.h>

using namespace std;

struct info {
    int tw, pw, tb, pb;
};

int n, k;
vector<info> iv;

vector<vector<int>> dp;

int look_up(int index, int time) {
    if (dp[index][time] != -1) return dp[index][time];
    if (index == n) return 0;

    int val = INT_MIN;

    if (time >= iv[index].tw) {
        val = max(val, look_up(index+1, time - iv[index].tw) + iv[index].pw);
    }
    if (time >= iv[index].tb) {
        val = max(val, look_up(index+1, time - iv[index].tb) + iv[index].pb);
    }

    dp[index][time] = val;
    return dp[index][time];
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
        cin >> el.tw >> el.pw >> el.tb >> el.pb;
    }

    cout << sol();

    return 0;
}