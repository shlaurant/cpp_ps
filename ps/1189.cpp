#include <bits/stdc++.h>

using namespace std;

int r, c, k;
char m[5][5];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
bool v[5][5];

int dfs(int y, int x, int l) {
    ++l;
    if (l == k && y != 0 && x != c - 1) return 0;
    if (l == k && y == 0 && x == c - 1) return 1;

    int ret = 0;
    v[y][x] = true;

    for (auto i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
        if (!v[ny][nx] && m[ny][nx] == '.') {
            ret += dfs(ny, nx, l);
        }
    }
    v[y][x] = false;
    return ret;
}

int solve() {
    fill(&v[0][0], &v[0][0] + 25, false);
    return dfs(r - 1, 0, 0);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c >> k;
    for (auto i = 0; i < r * c; ++i) {
        cin >> m[i / c][i % c];
    }

    cout << solve();
}