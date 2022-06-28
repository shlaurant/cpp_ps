#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> coins;

vector<int> dp;

int sol() {
    dp.resize(k + 1);
    dp[0] = 1;
    for (auto j = 0; j < n; ++j) {
        for (auto i = 1; i < k + 1; ++i) {
            if (i - coins[j] >= 0) dp[i] += dp[i - coins[j]];
        }
    }
    return dp.back();
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