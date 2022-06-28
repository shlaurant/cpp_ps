#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> coins;

vector<int> dp;

int look_up(int i) {
    if (i < 1) {
        return 1e4 + 1;
    }
    if (dp[i] != 0) return dp[i];
    int mn = INT_MAX;
    for (auto el: coins) {
        mn = min(mn, look_up(i - el) + 1);
    }
    dp[i] = mn;
    return dp[i];
}

int sol() {
    dp.resize(k + 1);
    for (auto &el: coins) {
        if (el <= k) dp[el] = 1;
    }

    auto val = look_up(k);
    return val > 1e4 ? -1 : val;
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