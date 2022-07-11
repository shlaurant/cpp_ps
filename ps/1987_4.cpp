#include <bits/stdc++.h>

using namespace std;

int r, c;
vector<vector<char>> board;

int ret = 0;
vector<vector<bool>> visit;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void rec(int y, int x, int cnt, int track) {
    visit[y][x] = true;
    ++cnt;
    track |= (1 << (board[y][x] - 'A'));
    bool f = true;
    for (auto i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
        if (!visit[ny][nx] && !(track & (1 << (board[ny][nx] - 'A')))) {
            f = false;
            rec(ny, nx, cnt, track);
        }
    }
    if (f) ret = max(ret, cnt);
    visit[y][x] = false;
}

int sol() {
    visit.resize(r, vector<bool>(c));

    rec(0, 0, 0, 0);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

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