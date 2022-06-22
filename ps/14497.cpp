#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<pair<int, int>> np(const pair<int, int> &p) {
    vector<pair<int, int>> ret(4);
    ret[0] = {p.first + 1, p.second};
    ret[1] = {p.first - 1, p.second};
    ret[2] = {p.first, p.second + 1};
    ret[3] = {p.first, p.second - 1};
    return ret;
}

void dfs(const pair<int, int> &xy, queue<pair<int, int>> &q,
         vector<vector<int>> &vis, const vector<vector<char>> &vec,
         vector<vector<bool>> &vis_dfs) {
    int y, x;
    tie(y, x) = xy;
    vis_dfs[y][x] = true;

    for (const auto &nxy: np(xy)) {
        int ny, nx;
        tie(ny, nx) = nxy;
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (!vis_dfs[ny][nx] && (vec[ny][nx] == '0' || vec[ny][nx] == '*')) {
            if (vis[ny][nx] == -1) {
                q.push({ny, nx});
                vis[ny][nx] = vis[y][x];
            }
            dfs({ny, nx}, q, vis, vec, vis_dfs);
        }
    }
}

void _bfs(queue<pair<int, int>> &q, vector<vector<int>> &vis,
          vector<vector<char>> &vec) {
    int ori = vis[q.front().first][q.front().second];

    while (!q.empty()) {
        int cy, cx;
        tie(cy, cx) = q.front();
        if (vis[cy][cx] != ori) return;
        q.pop();

        int ny, nx;
        for (const auto &yx: np({cy, cx})) {
            tie(ny, nx) = yx;
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (vis[ny][nx] == -1 && (vec[ny][nx] == '1' || vec[ny][nx] == '#')) {
                vec[ny][nx] = '0';
                vis[ny][nx] = vis[cy][cx] + 1;
                q.push({ny, nx});
            }
        }
    }
}

int
sol(int y1, int x1, int y2, int x2, vector<vector<char>> &vec) {
    vector<vector<int>> vis_bfs(vec.size(), vector<int>(vec[0].size(), -1));
    vector<vector<bool>> vis_dfs(vec.size(), vector<bool>(vec[0].size()));
    queue<pair<int, int>> q;

    vis_bfs[y1][x1] = 0;
    q.push({y1, x1});

    while (!q.empty()) {
        if (vis_bfs[y2][x2] != -1) return vis_bfs[y2][x2];
        for (auto &el: vis_dfs) {
            fill(el.begin(), el.end(), false);
        }
        dfs(q.front(), q, vis_bfs, vec, vis_dfs);
        _bfs(q, vis_bfs, vec);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    int y1, x1, y2, x2;

    cin >> n >> m >> y1 >> x1 >> y2 >> x2;
    vector<vector<char>> vec(n, vector<char>(m));

    for (auto &r: vec) {
        for (auto &e: r) {
            cin >> e;
        }
    }

    cout << sol(y1 - 1, x1 - 1, y2 - 1, x2 - 1, vec);

    return 0;
}