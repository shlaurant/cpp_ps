#include <bits/stdc++.h>

using namespace std;

int n, m, c;
vector<int> jams;

vector<vector<vector<int>>> dp;

int look_up(int bag, int ji, int vol) {
    if (bag >= m) return 0;
    if (dp[bag][ji][vol] != -1) return dp[bag][ji][vol];

    int val = 0;
    for (auto i = 0; i < n; ++i) {
        if ((ji & 1 << i) && vol - jams[i] >= 0)
            val = max(val, look_up(bag, ji & ~(1 << i), vol - jams[i]) + 1);
    }
    val = max(val, look_up(bag + 1, ji, c));
    dp[bag][ji][vol] = val;

    return dp[bag][ji][vol];
}

int sol() {
    dp.resize(m, vector<vector<int>>(1 << n, vector<int>(c + 1, -1)));
    return look_up(0, (1 << n) - 1, c);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> c;
    jams.resize(n);
    for (auto &el: jams) {
        cin >> el;
    }

    cout << sol();

    return 0;
}