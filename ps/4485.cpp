#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> cave;

vector<vector<int>> dist;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int sol() {
    dist.clear();
    dist.resize(n, vector<int>(n));
    for (auto &rw: dist) {
        fill(rw.begin(), rw.end(), INT_MAX);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[0][0] = cave[0][0];
    pq.push({dist[0][0], 0});

    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int y = p.second / n, x = p.second % n;
        if (p.first > dist[y][x]) continue;
        for (auto i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if (dist[ny][nx] > p.first + cave[ny][nx]) {
                dist[ny][nx] = p.first + cave[ny][nx];
                pq.push({dist[ny][nx], n * ny + nx});
            }
        }
    }

    return dist[n - 1][n - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int p = 1;
    while (true) {
        cin >> n;
        if (n == 0) break;
        cave.clear();
        cave.resize(n, vector<int>(n));
        for (auto &rw: cave) {
            for (auto &el: rw) {
                cin >> el;
            }
        }
        cout << "Problem " << p << ": " << sol() << '\n';
        ++p;
    }

    return 0;
}