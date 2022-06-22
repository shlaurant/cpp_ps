#include <bits/stdc++.h>

using namespace std;

int r, c;
vector<vector<char>> board;

vector<vector<bool>> v;
int al = 0;
int ret = 0;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

bool is_ok(int y, int x) {
    return (1 << (board[y][x] - 'A') & al) == 0;
}

void dfs(int y, int x, int cnt) {
    bool has_moved = false;
    v[y][x] = true;
    ++cnt;
    al |= 1 << (board[y][x] - 'A');
    int ny, nx;
    for (auto i = 0; i < 4; ++i) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
        if (!v[ny][nx] && is_ok(ny, nx)) {
            dfs(ny, nx, cnt);
            has_moved = true;
        }
    }
    if (!has_moved) ret = max(ret, cnt);
    al &= ~(1 << (board[y][x] - 'A'));
    --cnt;
    v[y][x] = false;
}

int sol() {
    v.resize(r, vector<bool>(c));
    dfs(0, 0, 0);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    cin >> r >> c;
    board.resize(r, vector<char>(c));

    for (auto &rw: board) {
        for (auto &el: rw) {
            cin >> el;
        }
    }

    cout << sol();

    return 0;
}