#include <bits/stdc++.h>

using namespace std;

int r, c;
vector<vector<int>> castle;

vector<vector<int>> visit;
int cnt;
vector<int> vol;
int mx;

int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};

void dfs(int y, int x, int num) {
    visit[y][x] = num;
    ++vol[num];
    for (auto i = 0; i < 4; ++i) {
        if (castle[y][x] & (1 << i)) continue;
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
        if (visit[ny][nx] == 0) {
            dfs(ny, nx, num);
        }
    }
}

int sum(int y, int x) {
    for (auto i = 0; i < 4; ++i) {
        if (castle[y][x] & (1 << i)){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
            if(visit[y][x] != visit[ny][nx]){
                return vol[visit[y][x]] + vol[visit[ny][nx]];
            }
        }
    }
    return 0;
}

void sol() {
    visit.resize(r, vector<int>(c));

    int rn = 0;
    for (int y = 0; y < r; ++y) {
        for (int x = 0; x < c; ++x) {
            if (visit[y][x] == 0) {
                ++rn;
                vol.resize(rn + 1, 0);
                dfs(y, x, rn);
            }
        }
    }
    cnt = rn;

    mx = 0;
    for (int y = 0; y < r; ++y) {
        for (int x = 0; x < c; ++x) {
            if (visit[y][x] != 0) {
                mx = max(mx, sum(y, x));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> c >> r;
    castle.resize(r, vector<int>(c));
    for (auto &rw: castle) {
        for (auto &el: rw) {
            cin >> el;
        }
    }

    sol();

    cout << cnt << '\n';
    int t = 0;
    for (auto el: vol) {
        t = max(el, t);
    }
    cout << t << '\n';
    cout << mx;

    return 0;
}