#include <bits/stdc++.h>

using namespace std;

int t, w;
vector<vector<vector<int>>> dp;

void tab(int time, int tr, const vector<int> &seq) {
    for (auto j = 0; j <= w; ++j) {
        auto a = dp[time - 1][tr][j];
        auto b = -1;
        if (j < w) {
            b = dp[time - 1][(tr + 1) % 2][j + 1];
        }
        dp[time][tr][j] = max(a, b);
        if (seq[time] == tr) ++dp[time][tr][j];
    }
}

int sol(const vector<int> &seq) {
    dp[0][0][w] = seq[0] == 0 ? 1 : 0;
    dp[0][1][w - 1] = (dp[0][0][w] + 1) % 2;

    for (auto i = 1; i < t; ++i) {
        tab(i, 0, seq);
        tab(i, 1, seq);
    }


    int ret = 0;
    for (const auto &tr: dp[t - 1]) {
        for (const auto el: tr) {
            ret = max(ret, el);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t >> w;
    auto per = new vector<int>(t);
    for (auto &el: *per) {
        cin >> el;
        --el;
    }

    dp.resize(t, vector<vector<int>>(2, vector<int>(w + 1, -1)));

    cout << sol(*per);

    return 0;
}