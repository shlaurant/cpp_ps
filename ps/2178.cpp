#include <bits/stdc++.h>

using namespace std;

int n, m;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int g[100][100];
int v[100][100] = {0};

void bfs(queue<pair<int, int>> q, int y, int x) {
    v[y][x] = 1;
    q.push({y, x});
    while (q.size()) {
        int cy, cx;
        tie(cy, cx) = q.front();
        q.pop();
        for (auto i = 0; i < 4; i++) {
            int ny, nx;
            ny = cy + dy[i];
            nx = cx + dx[i];
            if (ny >= 0 && ny < 100 && nx >= 0 && nx < 100) {
                if (!v[ny][nx] && g[ny][nx] == 1) {
                    q.push({ny, nx});
                    v[ny][nx] = v[cy][cx] + 1;
                }
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    queue<pair<int, int>> q;

    cin >> n >> m;

    for (auto i = 0; i < n; ++i) {
        string input;
        cin >> input;
        for (auto j = 0; j < m; ++j) {
            g[i][j] = input[j] - '0';
        }
    }

    bfs(q, 0, 0);

    cout << v[n - 1][m - 1];

    return 0;
}