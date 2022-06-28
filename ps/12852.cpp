#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> dp;
int ans;
vector<int> av;

int look_up(int i) {
    if (i > n) return 1e6 + 1;
    if (dp[i].first != -1) {
        return dp[i].first;
    }
    int mn = INT_MAX;
    int prev = -1;
    if (look_up(i + 1) < mn) {
        mn = look_up(i + 1) + 1;
        prev = i + 1;
    }
    if (look_up(i * 2) < mn) {
        mn = look_up(i * 2) + 1;
        prev = i * 2;
    }
    if (look_up(i * 3) < mn) {
        mn = look_up(i * 3) + 1;
        prev = i * 3;
    }
    dp[i] = {mn, prev};
    return dp[i].first;
}

void sol() {
    dp.resize(n + 1, {-1, 0});
    dp[n] = {0, -1};

    ans = look_up(1);
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