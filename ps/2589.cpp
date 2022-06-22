#include <bits/stdc++.h>

using namespace std;

int h, w, v[50][50];
char m[50][50];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int bfs(int y, int x) {
    fill(&v[0][0], &v[0][0] + 2500, 0);
    queue<pair<int, int>> q;
    q.push({y, x});
    v[y][x] = 1;

    int ret = 0;

    while (!q.empty()) {
        int cy, cx;
        tie(cy, cx) = q.front();
        for (auto i = 0; i < 4; ++i) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if (m[ny][nx] == 'L' && v[ny][nx] == 0) {
                q.push({ny, nx});
                v[ny][nx] = v[cy][cx] + 1;
                ret = max(v[ny][nx], ret);
            }
        }
        q.pop();
    }

    return --ret;
}

int sol() {
    int mx = -1;
    for (auto y = 0; y < h; ++y) {
        for (auto x = 0; x < w; ++x) {
            if (m[y][x] == 'L') mx = max(mx, bfs(y, x));
        }
    }
    return mx;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> h >> w;
    for (auto i = 0; i < h * w; ++i) {
        cin >> m[i / w][i % w];
    }

    cout << sol();
    return 0;
}