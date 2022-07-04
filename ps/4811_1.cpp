#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<ll>> dp;

ll look_up(int w, int h) {
    if (w == 0 && h == 0) return 1;
    if (dp[w][h] != -1) return dp[w][h];

    ll val = 0;
    if (w > 0) {
        val += look_up(w - 1, h + 1);
    }
    if (h > 0) {
        val += look_up(w, h - 1);
    }

    dp[w][h] = val;
    return dp[w][h];
}

ll sol(int n) {
    return look_up(n, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    dp.resize(31, vector<ll>(31, -1));

    int n;
    while (cin >> n) {
        if (n == 0) break;
        cout << sol(n) << '\n';
    }

    return 0;
}