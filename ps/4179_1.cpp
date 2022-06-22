#include <bits/stdc++.h>

using namespace std;

int r, c;
char m[1000][1000];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void draw_fmap(int (&ret)[1000][1000]) {
    queue<pair<int, int>> q;
    fill(&ret[0][0], &ret[0][0] + 1000000, INT_MAX);
    for (auto y = 0; y < r; ++y) {
        for (auto x = 0; x < c; ++x) {
            if (m[y][x] == 'F') {
                q.push({y, x});
                ret[y][x] = 1;
            }
        }
    }

    while (!q.empty()) {
        int cy, cx, ny, nx;
        tie(cy, cx) = q.front();

        for (auto i = 0; i < 4; ++i) {
            ny = cy + dy[i];
            nx = cx + dx[i];
            if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
            if (ret[ny][nx] == 0 && m[ny][nx] != '#') {
                ret[ny][nx] = ret[cy][cx] + 1;
                q.push({ny, nx});
            }
        }

        q.pop();
    }
}

int bfs(int iy, int ix, int (&f)[1000][1000]) {
    int ret = INT_MAX;
    int v[1000][1000];
    fill(&v[0][0], &v[0][0] + 1000000, 0);
    queue<pair<int, int>> q;
    q.push({iy, ix});
    v[iy][ix] = 1;

    while (!q.empty()) {
        int y, x, ny, nx;
        tie(y, x) = q.front();

        for (auto i = 0; i < 4; ++i) {
            ny = y + dy[i];
            nx = x + dx[i];
            if (ny < 0 || ny >= r || nx < 0 || nx >= c) {
                ret = min(ret, v[y][x]);
                continue;
            }
            if (m[ny][nx] == '.' && v[ny][nx] == 0 && f[ny][nx] > v[y][x] + 1) {
                v[ny][nx] = v[y][x] + 1;
                q.push({ny, nx});
            }
        }

        q.pop();
    }
    return ret;
}

int sol() {
    int f[1000][1000];
    draw_fmap(f);

    int iy, ix;
    for (auto y = 0; y < r; ++y) {
        for (auto x = 0; x < c; ++x) {
            if (m[y][x] == 'J') {
                iy = y;
                ix = x;
            }
        }
    }

    return bfs(iy, ix, f);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;
    cout << "dfdfd\n";
    for (auto y = 0; y < r; ++y) {
        for (auto x = 0; x < c; ++x) {
            cin >> m[y][x];
        }
        cout << "dfdfd\n";
    }

    auto ans = sol();
    ans == INT_MAX ? cout << "IMPOSSIBLE" : cout << ans;
    return 0;
}