#include <bits/stdc++.h>

using namespace std;

int r, c;
char m[100][100];
char v[100][100];
int iy, ix;
vector<pair<int, int>> fv;

int ret = INT_MAX;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void spread_fire(stack<vector<pair<int, int>> *> &s) {
    auto ori = fv.size();
    auto vec = new vector<pair<int, int>>();
    for (auto i = 0; i < ori; ++i) {
        int y, x, ny, nx;
        tie(y, x) = fv[i];
        for (auto j = 0; j < 4; ++j) {
            ny = y + dy[j];
            nx = x + dx[j];
            if (ny < 0 || ny >= r || nx < 0 || nx >= 0) continue;
            if (m[ny][nx] == '.') {
                m[ny][nx] = 'F';
                vec->push_back({ny, nx});
                fv.push_back({ny, nx});
            }
        }
    }
    s.push(vec);
}

void rollback_fire(stack<vector<pair<int, int>> *> &s) {
    auto vec = s.top();
    for (const auto &yx: *vec) {
        m[yx.first][yx.second] = '.';
    }
    fv.erase(fv.end() - vec->size(), fv.end());
    s.pop();
}

void sol(int y, int x, int cnt, stack<vector<pair<int, int>> *> &s) {
    if (cnt >= ret) return;
    if (y == r - 1 || x == c - 1) {
        ret = min(++cnt, ret);
        return;
    }

    spread_fire(s);
    v[y][x] = 1;
    int ny, nx;
    for (auto i = 0; i < 4; ++i) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
        if (v[ny][nx] == 0 && m[ny][nx] == '.') {
            m[y][x] = '.';
            m[ny][nx] = 'J';
            sol(ny, nx, cnt + 1, s);
            m[y][x] = 'J';
            m[ny][nx] = '.';
        }
    }
    v[y][x] = 0;
    rollback_fire(s);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    stack<vector<pair<int, int>> *> s;
    fill(&v[0][0], &v[0][0] + 10000, 0);

    cin >> r >> c;
    for (auto y = 0; y < r; ++y) {
        for (auto x = 0; x < c; ++x) {
            cin >> m[y][x];
            if (m[y][x] == 'J') {
                iy = y, ix = x;
            }
            if (m[y][x] == 'F') fv.push_back({y, x});
        }
    }

    sol(iy, ix, 0, s);
    ret == INT_MAX ? cout << "IMPOSSIBLE" : cout << ret;
}