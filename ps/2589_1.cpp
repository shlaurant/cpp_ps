//1122
#include <bits/stdc++.h>

using namespace std;

int r, c;
vector<vector<char>> mp;

vector<vector<int>> visit;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    visit[y][x] = 1;
    int cur_max = 1;

    while (!q.empty()) {
        int cy, cx;
        tie(cy, cx) = q.front();
        q.pop();
        for (auto i = 0; i < 4; ++i) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;

            if (visit[ny][nx] == 0 && mp[ny][nx] == 'L') {
                visit[ny][nx] = visit[cy][cx] + 1;
                cur_max = visit[ny][nx];
                q.push({ny, nx});
            }
        }
    }

    return cur_max - 1;
}

int sol() {
    int ret = 0;

    visit.resize(r, vector<int>(c));

    for (auto y = 0; y < r; ++y) {
        for (auto x = 0; x < c; ++x) {
            if (mp[y][x] == 'L') {
                for (auto &rw: visit) {
                    fill(rw.begin(), rw.end(), 0);
                }
                ret = max(ret, bfs(y, x));
            }
        }
    }

    return ret;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c;
    mp.resize(r, vector<char>(c));
    for (auto &rw: mp) {
        for (auto &el: rw) {
            cin >> el;
        }
    }

    cout << sol();

    return 0;
}