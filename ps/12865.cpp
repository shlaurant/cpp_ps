#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<pair<int, int>> goods;

vector<vector<int>> dp;

int look_up(int w, int i) {
    if (w <= 0 || i < 0) return 0;
    if (dp[w][i] != -1) return dp[w][i];

    if (w - goods[i].first >= 0) {
        dp[w][i] = max(look_up(w - goods[i].first, i - 1) + goods[i].second,
                       look_up(w, i - 1));
    } else {
        dp[w][i] = look_up(w, i - 1);
    }
    return dp[w][i];
}

int sol() {
    dp.resize(k + 1, vector<int>(n, -1));
    dp[0][0] = 0;
    return look_up(k, n - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    goods.resize(n);
    for (auto &el: goods) {
        cin >> el.first >> el.second;
    }

    cout << sol();

    return 0;
}