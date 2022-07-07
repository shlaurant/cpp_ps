#include <bits/stdc++.h>

using namespace std;

int r, c;
vector<vector<int>> board;

int t;
int last_cnt;

vector<vector<int>> visit;

bool not_empty() {
    for (const auto &rw: board) {
        for (auto el: rw) {
            if (el == 1) return true;
        }
    }
    return false;
}

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x) {
    visit[y][x] = 1;
    for (auto i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
        if (visit[ny][nx] == 0) {
            if (board[ny][nx] == 1) visit[ny][nx] = 2;
            else dfs(ny, nx);
        }
    }
}

int melt() {
    int ret = 0;
    for (auto y = 0; y < r; ++y) {
        for (auto x = 0; x < c; ++x) {
            if (visit[y][x] == 2) {
                ++ret;
                board[y][x] = 0;
            }
        }
    }
    return ret;
}

void sol() {
    visit.resize(r, vector<int>(c));
    int cnt;
    t = 0;
    while (not_empty()) {
        for (auto &rw: visit) {
            fill(rw.begin(), rw.end(), 0);
        }
        dfs(0, 0);
        cnt = melt();
        ++t;
    }
    last_cnt = cnt;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c;
    board.resize(r, vector<int>(c));
    for (auto &rw: board) {
        for (auto &el: rw) {
            cin >> el;
        }
    }

    sol();
    cout << t << '\n';
    cout << last_cnt;

    return 0;
}