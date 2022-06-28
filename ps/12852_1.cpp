#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> dp;
int ans;
vector<int> av;

void tab() {
    for (auto i = n; i > 1; --i) {
        if (i % 3 == 0 && dp[i].first + 1 < dp[i / 3].first) {
            dp[i / 3].first = dp[i].first + 1;
            dp[i / 3].second = i;
        }

        if (i % 2 == 0 && dp[i].first + 1 < dp[i / 2].first) {
            dp[i / 2].first = dp[i].first + 1;
            dp[i / 2].second = i;
        }

        if (dp[i].first + 1 < dp[i - 1].first) {
            dp[i - 1].first = dp[i].first + 1;
            dp[i - 1].second = i;
        }
    }
}

void sol() {
    dp.resize(n + 1, {INT_MAX, 0});
    dp[n] = {0, -1};
    tab();
    ans = dp[1].first;

    auto cur = 1;
    while (dp[cur].second != -1) {
        av.push_back(cur);
        cur = dp[cur].second;
    }
    av.push_back(cur);
    reverse(av.begin(), av.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    sol();

    cout << ans << '\n';
    for (auto el: av) {
        cout << el << ' ';
    }

    return 0;
}