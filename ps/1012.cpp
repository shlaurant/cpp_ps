#include <bits/stdc++.h>

using namespace std;

int t, m, n, k, y, x, ny, nx;
int g[50][50] = {0};
int v[50][50] = {0};
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x) {
    v[y][x] = 1;
    for (auto i = 0; i < 4; ++i) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
            continue;
        }
        if (g[ny][nx] == 1 && v[ny][nx] == 0) {
            dfs(ny, nx);
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    for (auto i = 0; i < t; ++i) {
        int ret = 0;

        fill(&g[0][0], &g[0][0] + 2500, 0);
        fill(&v[0][0], &v[0][0] + 2500, 0);
        cin >> m >> n >> k;

        for (auto j = 0; j < k; ++j) {
            cin >> x >> y;
            g[y][x] = 1;
        }

        for (auto q = 0; q < n; ++q) {
            for (auto w = 0; w < m; ++w) {
                if (g[q][w] == 1 && v[q][w] == 0) {
                    ++ret;
                    dfs(q, w);
                }
            }
        }

        cout << ret << "\n";
    }
}