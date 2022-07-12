//1553
#include <bits/stdc++.h>

using namespace std;

int t, w;
vector<int> seq;

vector<vector<vector<int>>> dp;

void tab() {
    if (seq[0] == 0) {
        dp[0][w][0] = 1;
        dp[0][w - 1][1] = 0;
    } else {
        dp[0][w][0] = 0;
        dp[0][w - 1][1] = 1;
    }
    for (auto i = 0; i < t - 1; ++i) {
        for (auto j = 0; j <= w; ++j) {
            for (auto ct = 0; ct <= 1; ++ct) {
                if (dp[i][j][ct] != -1) {
                    if (seq[i + 1] == ct) {
                        dp[i + 1][j][ct] = max(dp[i + 1][j][ct],
                                               dp[i][j][ct] + 1);
                        if(j >0)
                        dp[i + 1][j - 1][ct ^ 1] = max(dp[i + 1][j - 1][ct ^ 1],
                                                       dp[i][j][ct]);
                    } else {
                        dp[i + 1][j][ct] = max(dp[i + 1][j][ct], dp[i][j][ct]);
                        if(j >0)
                        dp[i + 1][j - 1][ct ^ 1] = max(dp[i + 1][j - 1][ct ^ 1],
                                                       dp[i][j][ct] + 1);
                    }
                }
            }
        }
    }
}

int find_max() {
    int mx = 0;
    for (const auto &rw: dp[t - 1]) {
        for (auto el: rw) {
            mx = max(mx, el);
        }
    }

    return mx;
}

int sol() {
    dp.resize(t, vector<vector<int>>(w + 1, vector<int>(2, -1)));
    tab();
    return find_max();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t >> w;
    seq.resize(t);
    for (auto &el: seq) {
        cin >> el;
        --el;
    }

    cout << sol();

    return 0;
}