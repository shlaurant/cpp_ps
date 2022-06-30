#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<int> seq;
vector<vector<ll>> dp;

ll look_up(int index, int val) {
    if (dp[index][val] != -1) return dp[index][val];

    ll ret = 0;
    if (val + seq[index] <= 20) {
        ret += look_up(index - 1, val + seq[index]);
    }

    if (val - seq[index] >= 0) {
        ret += look_up(index - 1, val - seq[index]);
    }
    dp[index][val] = ret;

    return dp[index][val];
}

ll sol() {
    dp.resize(n - 1, vector<ll>(21, -1));
    for (auto &el: dp[0]) {
        el = 0;
    }
    dp[0][seq[0]] = 1;

    return look_up(n - 2, seq[n - 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    seq.resize(n);
    for (auto &el: seq) {
        cin >> el;
    }

    cout << sol();

    return 0;
}