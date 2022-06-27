#include <bits/stdc++.h>

using namespace std;

int t;
vector<int> dp;
bool f = true;

int lookup(int n) {
    if (dp[n] == -1) {
        dp[n] = lookup(n - 3) + n/2 + 1;
    }
    return dp[n];
}

int sol(int n) {
    if (f) {
        dp.resize(100001, -1);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        f = false;
    }

    return lookup(n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    for (auto i = 0; i < t; ++i) {
        int n;
        cin >> n;
        cout << sol(n) << '\n';
    }

    return 0;
}