#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> coins;

vector<int> dp;

void tab() {
    dp[0] = 1;
    for (auto i = 0; i < n; ++i) {
        for (auto j = 1; j < k + 1; ++j) {
            if (j - coins[i] >= 0) {
                dp[j] += dp[j - coins[i]];
            }
        }
    }
}

int sol() {
    dp.resize(k + 1);
    tab();
    return dp[k];
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