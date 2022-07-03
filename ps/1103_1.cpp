#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> board;

vector<vector<int>> dp;
vector<vector<bool>> visit;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int look_up(int y, int x) {
    if (y < 0 || y >= n || x < 0 || x >= m) return 0;
    if (board[y][x] == -1) return 0;

    if (visit[y][x]) {
        cout << -1;
        exit(0);
    }
    if (dp[y][x] != -1) return dp[y][x];

    visit[y][x] = true;
    int val = INT_MIN;
    for (auto i = 0; i < 4; ++i) {
        val = max(val, look_up(y + board[y][x] * dy[i],
                               x + board[y][x] * dx[i]) + 1);
    }

    dp[y][x] = val;
    visit[y][x] = false;
    return dp[y][x];
}

int sol() {
    visit.resize(n, vector<bool>(m));
    dp.resize(n, vector<int>(m, -1));
    return look_up(0, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    board.resize(n, vector<int>(m));
    char c;
    for (auto &rw: board) {
        for (auto &el: rw) {
            cin >> c;
            if (c == 'H') el = -1;
            else el = (int) c - '0';
        }
    }

    cout << sol();

    return 0;
}