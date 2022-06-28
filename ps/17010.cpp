#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> house;

vector<vector<vector<int>>> dp;

bool not_avail(int r, int c, int dir) {
    switch (dir) {
        case 0:
            return c - 1 < 0 || house[r][c] == 1 || house[r][c - 1] == 1;
        case 1:
            return r - 1 < 0 || house[r][c] == 1 || house[r - 1][c] == 1;
        case 2:
            return c - 1 < 0 || house[r][c] == 1 || house[r][c - 1] == 1 ||
                   r - 1 < 0 || house[r][c] == 1 || house[r - 1][c] == 1 ||
                   house[r - 1][c - 1] == 1;
    }
}

int lookup(int r, int c, int dir) {
    if (r < 0 || r >= n || c < 0 || c >= n) return 0;
    if (dp[r][c][dir] != -1) return dp[r][c][dir];
    if (not_avail(r, c, dir)) {
        dp[r][c][dir] = 0;
        return 0;
    }

    int ret = 0;
    switch (dir) {
        case 0:
            ret += lookup(r, c - 1, dir);
            ret += lookup(r, c - 1, 2);
            break;
        case 1:
            ret += lookup(r - 1, c, dir);
            ret += lookup(r - 1, c, 2);
            break;
        case 2:
            ret += lookup(r - 1, c - 1, 0);
            ret += lookup(r - 1, c - 1, 1);
            ret += lookup(r - 1, c - 1, 2);
            break;
    }
    dp[r][c][dir] = ret;
    return ret;
}

int sol() {
    dp.resize(n, vector<vector<int>>(n, vector<int>(3, -1)));
    dp[0][1][0] = 1;
    return lookup(n - 1, n - 1, 0) + lookup(n - 1, n - 1, 1) +
           lookup(n - 1, n - 1, 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    house.resize(n, vector<int>(n));
    for (auto &rw: house) {
        for (auto &el: rw) {
            cin >> el;
        }
    }

    cout << sol();

    return 0;
}