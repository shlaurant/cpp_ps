#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> seq;

vector<vector<int>> dp;

int sol(int s, int e) {
    if (dp[s][e] != -1) return dp[s][e];

    if (seq[s] != seq[e - 1]) {
        dp[s][e] = 0;
    } else if (e - s <= 2) {
        dp[s][e] = 1;
    } else {
        dp[s][e] = sol(s + 1, e - 1);
    }
    return dp[s][e];
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

    dp.resize(n, vector<int>(n + 1, -1));

    cin >> m;
    for (auto i = 0; i < m; ++i) {
        int s, e;
        cin >> s >> e;
        cout << sol(s - 1, e) << '\n';
    }

    return 0;
}