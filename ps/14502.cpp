#include <bits/stdc++.h>

using namespace std;

int n, m;

int a[8][8];
int b[8][8];
int v[8][8];
vector<pair<int, int>> vec;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int dfs(int y, int x) {
    int ret = 1;
    v[y][x] = 1;
    for (auto i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (b[ny][nx] == 0 && v[ny][nx] == 0) {
            ret += dfs(ny, nx);
        }
    }
    return ret;
}

int sol() {
    int ret = 0;

    for (auto i = 0; i < n * m; ++i) {
        if (a[i / m][i % m] == 0) {
            vec.push_back({i / m, i % m});
        }
    }

    for (auto i = 0; i < vec.size() - 2; ++i) {
        for (auto j = i + 1; j < vec.size() - 1; ++j) {
            for (auto k = j + 1; k < vec.size(); ++k) {
                int cret = 0;
                copy(&a[0][0], &a[0][0] + 64, &b[0][0]);
                fill(&v[0][0], &v[0][0] + 64, 0);

                b[vec[i].first][vec[i].second] = 1;
                b[vec[j].first][vec[j].second] = 1;
                b[vec[k].first][vec[k].second] = 1;

                for (auto t = 0; t < n * m; ++t) {
                    if (b[t / m][t % m] == 2 && v[t / m][t % m] == 0) {
                        dfs(t / m, t % m);
                    }
                }

                for (auto t = 0; t < n * m; ++t) {
                    if (b[t / m][t % m] == 0 && v[t / m][t % m] == 0) {
                        cret += dfs(t / m, t % m);
                    }
                }
                ret = max(ret, cret);
            }
        }
    }

    return ret;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (auto i = 0; i < n * m; ++i) {
        cin >> a[i / m][i % m];
    }

    cout << sol();

    return 0;
}