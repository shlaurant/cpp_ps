#include <bits/stdc++.h>

using namespace std;

int n, l, r;
int m[50][50];
int v[50][50];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

bool need_move() {
    for (auto y = 0; y < n; ++y) {
        for (auto x = 0; x < n; ++x) {
            int ny, nx;
            for (auto i = 0; i < 4; ++i) {
                ny = y + dy[i];
                nx = x + dx[i];
                if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                int sub = abs(m[ny][nx] - m[y][x]);
                if (l <= sub && sub <= r) return true;
            }
        }
    }
    return false;
}

void dfs(int y, int x, vector<pair<int, int>> &vec) {
    v[y][x] = 1;
    vec.push_back({y, x});

    int ny, nx;
    for (auto i = 0; i < 4; ++i) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        int sub = abs(m[ny][nx] - m[y][x]);
        if (l <= sub && sub <= r && v[ny][nx] == 0) dfs(ny, nx, vec);
    }
}

int sol() {
    int ret = 0;
    vector<pair<int, int>> vec;
    while (need_move()) {
        ++ret;
        fill(&v[0][0], &v[0][0] + 2500, 0);
        for (auto i = 0; i < n * n; ++i) {
            if (v[i / n][i % n] != 0) continue;
            vec.clear();
            dfs(i / n, i % n, vec);
            int sum = 0;
            for (const auto &e: vec) {
                sum += m[e.first][e.second];
            }
            auto a = sum / vec.size();
            for (const auto &e: vec) {
                m[e.first][e.second] = a;
            }
        }
    }
    return ret;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l >> r;
    for (auto i = 0; i < n * n; ++i) {
        cin >> m[i / n][i % n];
    }

    cout << sol();
}