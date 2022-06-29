#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> hp_ple;

vector<int> dp;

void tab() {
    for (auto j = 0; j < n; ++j) {
        for (auto i = 100; i >= 0; --i) {
            if(i-hp_ple[j].first > 0)
            dp[i] = max(dp[i-hp_ple[j].first] + hp_ple[j].second, dp[i]);
        }
    }
}

int sol() {
    dp.resize(101);

    tab();

    return dp[100];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    hp_ple.resize(n);
    for (auto &el: hp_ple) {
        cin >> el.first;
    }
    for (auto &el: hp_ple) {
        cin >> el.second;
    }

    cout << sol();

    return 0;
}