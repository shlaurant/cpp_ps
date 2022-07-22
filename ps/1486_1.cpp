#include <bits/stdc++.h>

using namespace std;

const int mxt = 1000001;

int r, c, t, d;
vector<vector<int>> mt;

vector<vector<int>> dist;

struct info {
    int y, x, t;
};

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int cost(int y1, int x1, int y2, int x2) {
    if (mt[y1][x1] >= mt[y2][x2]) return 1;
    else return abs(mt[y1][x1] - mt[y2][x2]) * abs(mt[y1][x1] - mt[y2][x2]);
}

void make_dist(int y, int x) {
    for (auto i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
        if(abs(mt[y][x] - mt[ny][nx]) > t) continue;
        dist[c * y + x][c * ny + nx] = cost(y, x, ny, nx);
    }
}

void make_dist() {
    dist.resize(r*c, vector<int>(r*c, INT_MAX));
    for (auto i = 0; i < r * c; ++i) {
        dist[i][i] = 0;
    }

    for (auto y = 0; y < r; ++y) {
        for (auto x = 0; x < c; ++x) {
            make_dist(y, x);
        }
    }

    for (auto k = 0; k < r * c; ++k) {
        for (auto i = 0; i < r * c; ++i) {
            for (auto j = 0; j < r * c; ++j) {
                if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

int sol() {
    int ret = 0;

    make_dist();

    for (auto y = 0; y < r; ++y) {
        for (auto x = 0; x < c; ++x) {
            if (dist[0][c * y + x] == INT_MAX ||
                dist[c * y + x][0] == INT_MAX)
                continue;
            if (dist[0][c * y + x] + dist[c * y + x][0] > d) continue;
            if (mt[y][x] > ret) ret = mt[y][x];
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c >> t >> d;
    mt.resize(r, vector<int>(c));

    for (auto &rw: mt) {
        for (auto &el: rw) {
            char ch;
            cin >> ch;
            ch >= 'a' ? el = ch - 'a' + 26 : el = ch - 'A';
        }
    }

    cout << sol();

    return 0;
}