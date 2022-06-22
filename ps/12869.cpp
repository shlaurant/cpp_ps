#include <bits/stdc++.h>

using namespace std;

int n, hp[] = {0, 0, 0};

int v[61][61][61];
tuple<int, int, int> d[] = {{9, 3, 1}, {9, 1, 3}, {3, 9, 1}, {3, 1, 9},
                            {1, 3, 9}, {1, 9, 3}};

void bfs(tuple<int, int, int> xyz) {
    int x, y, z;
    tie(x, y, z) = xyz;

    queue<tuple<int, int, int>> q;
    v[x][y][z] = 1;
    q.push(xyz);

    while (!q.empty()) {
        tie(x, y, z) = q.front();
        if (v[0][0][0] != 0) return;
        int nx, ny, nz, dx, dy, dz;
        for (auto i = 0; i < 6; ++i) {
            tie(dx, dy, dz) = d[i];
            nx = max(0, x - dx);
            ny = max(0, y - dy);
            nz = max(0, z - dz);
            if (v[nx][ny][nz] == 0) {
                v[nx][ny][nz] = v[x][y][z] + 1;
                q.push({nx, ny, nz});
            }
        }
        q.pop();
    }
}

int sol() {
    fill(&v[0][0][0], &v[0][0][0] + 61 * 61 * 61, 0);
    bfs({hp[0], hp[1], hp[2]});
    return v[0][0][0] - 1;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (auto i = 0; i < n; ++i) {
        cin >> hp[i];
    }

    cout << sol();
    return 0;
}