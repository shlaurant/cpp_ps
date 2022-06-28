#include <bits/stdc++.h>

using namespace std;

int t, w;
vector<int> seq;

vector<vector<vector<int>>> dp;

void foo(int time, int cnt, int tr) {
    if (dp[time][tr][cnt] != -1) {
        int mx = dp[time][tr][cnt];
        if (seq[time + 1] == tr) ++mx;
        dp[time + 1][tr][cnt] = max(mx, dp[time + 1][tr][cnt]);
        if (cnt > 0) {
            mx = dp[time][tr][cnt];
            if (seq[time + 1] != tr) ++mx;
            dp[time + 1][tr ^ 1][cnt - 1]= max(mx, dp[time + 1][tr ^ 1][cnt - 1]);
        }
    }
}
void tab() {
    for (auto i = 0; i < t - 1; ++i) {
        for (auto j = 0; j <= w; ++j) {
            foo(i, j, 0);
            foo(i, j, 1);
        }
    }
}

int find_max() {
    int ret = 0;
    for (auto el: dp[t - 1][0]) {
        ret = max(ret, el);
    }
    for (auto el: dp[t - 1][1]) {
        ret = max(ret, el);
    }
    return ret;
}

int sol() {
    dp.resize(t, vector<vector<int>>(2, vector<int>(w + 1, -1)));
    if (seq[0]) {
        dp[0][seq[0]][w - 1] = 1;
        dp[0][seq[0] ^ 1][w] = 0;
    } else {
        dp[0][seq[0]][w] = 1;
        dp[0][seq[0] ^ 1][w - 1] = 0;
    }

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