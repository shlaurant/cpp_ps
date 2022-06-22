#include <bits/stdc++.h>

using namespace std;

int sy, sx, m[100][100], v[100][100];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int t, s;

void dfs(int y, int x) {
    v[y][x] = 1;
    for (auto i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= sy || nx < 0 || nx >= sx) continue;
        if (m[ny][nx] == 0 && v[ny][nx] == 0) {
            dfs(ny, nx);
        }
    }
    return;
}

int cur_s(){
    int ret = 0;

    for (auto i = 0; i < sy; ++i) {
        for (auto j = 0; j < sx; ++j) {
            if (m[i][j] == 1) {
                ++ret;
            }
        }
    }

    return ret;
}

void solve() {
    while (cur_s() > 0) {
        fill(&v[0][0], &v[0][0] + 10000, 0);
        dfs(0, 0);

        s = cur_s();
        ++t;
        for (auto i = 0; i < sy; ++i) {
            for (auto j = 0; j < sx; ++j) {
                if (m[i][j] == 1) {
                    for (auto k = 0; k < 4; ++k) {
                        int ny = i + dy[k];
                        int nx = j + dx[k];
                        if (ny < 0 || ny >= sy || nx < 0 || nx >= sx) continue;
                        if (v[ny][nx] == 1) {
                            m[i][j] = 0;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> sy >> sx;

    for (auto i = 0; i < sy * sx; ++i) {
        cin >> m[i / sx][i % sx];
    }

    solve();

    cout << t << '\n' << s;
}