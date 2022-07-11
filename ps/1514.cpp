#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> pwd;
vector<int> cur;

int dp[101][10][10][10][2];

int roll(int index, int dist) {
    return (cur[index] + dist + 10) % 10;
}

int look_up(int index, int a, int b, int c, int f) {
    if (dp[index][a][b][c][f] != -1) return dp[index][a][b][c][f];
    if (index == n) return 0;

    if (pwd[index] == roll(index, a)) {
        dp[index][a][b][c][f] =
                min(look_up(index + 1, b, c, 0, 0),
                    look_up(index + 1, b, c, 0, 1));
        return dp[index][a][b][c][f];
    }

    int &val = dp[index][a][b][c][f];
    val = 1e3 + 1;

    int d = f == 1 ? 1 : -1;
    for (auto i = 1; i <= 3; ++i) {
        val = min(val, look_up(index, (a + d * i + 10) % 10, b, c, f) + 1);
        val = min(val,
                  look_up(index, (a + d * i + 10) % 10, (b + d * i + 10) % 10,
                          c, f) + 1);
        val = min(val,
                  look_up(index, (a + d * i + 10) % 10, (b + d * i + 10) % 10,
                          (c + d * i + 10) % 10, f) + 1);
    }

    dp[index][a][b][c][f] = val;
    return dp[index][a][b][c][f];
}

int sol() {
    fill((&dp)[0][0][0][0][0], (&dp)[0][0][0][0][0] + 202000, -1);
    return min(look_up(0, 0, 0, 0, 0), look_up(0, 0, 0, 0, 1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    pwd.resize(n);
    cur.resize(n);
    char c;
    for (auto &el: cur) {
        cin >> c;
        el = c - '0';
    }

    for (auto &el: pwd) {
        cin >> c;
        el = c - '0';
    }

    cout << sol();

    return 0;
}