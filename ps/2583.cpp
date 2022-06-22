#include <bits/stdc++.h>

using namespace std;

int sy, sx, k, ny, nx;
int g[100][100] = {0};
int v[100][100] = {0};
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int size;

void dfs(int y, int x) {
    v[y][x] = 1;
    ++size;

    for (auto i = 0; i < 4; ++i) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (ny < 0 || ny >= sy || nx < 0 || nx >= sx) continue;
        if (v[ny][nx] == 0 && g[ny][nx] == 0) {
            dfs(ny, nx);
        }
    }
}

void draw(int lx, int ly, int rx, int ry) {
    for (auto i = lx; i < rx; ++i) {
        for (auto j = ly; j < ry; ++j) {
            g[j][i] = 1;
        }
    }
}

int main() {
    vector<int> sv;

    scanf("%d %d %d", &sy, &sx, &k);

    for (auto i = 0; i < k; ++i) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        draw(a, b, c, d);
    }

    int cnt = 0;

    for (auto i = 0; i < sy; ++i) {
        for (auto j = 0; j < sx; ++j) {
            if (g[i][j] == 0 && v[i][j] == 0) {
                size = 0;
                dfs(i, j);
                ++cnt;
                sv.push_back(size);
            }
        }
    }

    cout << cnt << "\n";
    sort(sv.begin(), sv.end());
    for (auto i: sv) {
        cout << i << " ";
    }
}