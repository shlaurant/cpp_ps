#include <bits/stdc++.h>

using namespace std;

long long sol(int n) {
    vector<long long> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (auto i = 2; i < n + 1; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    cout << sol(n);

    return 0;
}