#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<pair<int, int>> candy;

vector<int> dp;

void tab() {
    for (auto i = 0; i < m + 1; ++i) {
        for (auto j = 0; j < n; ++j) {
            if (candy[j].second + i <= m) {
                dp[i + candy[j].second] = max(dp[i + candy[j].second],
                                              dp[i] + candy[j].first);
            }
        }
    }
}

int sol() {
    dp.resize(m+1);
    fill(dp.begin(), dp.end(), 0);
    tab();
    return dp[m];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    double temp;
    while (true) {
        cin >> n >> temp;
        if (n == 0) break;
        m = (int) round(temp * 100);
        candy.resize(n);
        for (auto &el: candy) {
            cin >> el.first >> temp;
            el.second = (int) round(temp * 100);
        }
        cout << sol() << '\n';
    }

    return 0;
}