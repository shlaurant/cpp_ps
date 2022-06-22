#include <bits/stdc++.h>

using namespace std;

int n, ny, nx, ret = 0;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int g[100][100] = {0};
int v[100][100] = {0};

void dfs(int y, int x) {
    v[y][x] = 1;
    for (auto i = 0; i < 4; ++i) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (g[ny][nx] > 0 && v[ny][nx] == 0) {
            dfs(ny, nx);
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int mx = 0;
    for (auto i = 0; i < n * n; ++i) {
        cin >> g[i / n][i % n];
        mx = max(mx, g[i / n][i % n]);
    }

    while (mx) {
        fill(&v[0][0], &v[0][0] + 10000, 0);
        int temp = 0;
        for (auto i = 0; i < n * n; ++i) {
            if (g[i / n][i % n] > 0 && v[i / n][i % n] == 0) {
                ++temp;
                dfs(i / n, i % n);
            }
        }
        ret = max(ret, temp);

        for (auto i = 0; i < n * n; ++i) {
            --g[i / n][i % n];
        }

        --mx;
    }

    cout << ret;
}