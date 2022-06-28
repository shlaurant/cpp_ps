#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<ll>> dp;

ll lookup(int n, int m) {
    if (dp[n][m] != -1) return dp[n][m];
    ll ret = 0;
    if (n > 0) ret += lookup(n - 1, m + 1);
    if (m > 0) ret += lookup(n, m - 1);
    dp[n][m] = ret;
    return ret;
}

ll sol(int n) {
    return lookup(n, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    dp.resize(31, vector<ll>(31, -1));
    dp[0][0] = 0;
    dp[0][1] = 1;
    dp[1][0] = 1;

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        cout << sol(n) << '\n';
    }

    return 0;
}