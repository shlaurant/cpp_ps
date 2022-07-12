//1637
#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> coins;

vector<int> dp;

void tab() {
    dp[0] = 0;
    for (auto i = 0; i < n; ++i) {
        auto coin = coins[i];
        for (auto j = 0; j <= k; ++j) {
            if (j - coin >= 0) {
                dp[j] = min(dp[j], dp[j - coin] + 1);
            }
        }
    }
}

int sol() {
    dp.resize(k + 1, 1e6);
    tab();
    return dp[k] <= k ? dp[k] : -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    coins.resize(n);
    for (auto &el: coins) {
        cin >> el;
    }

    cout << sol();

    return 0;
}