#include <bits/stdc++.h>

using namespace std;

const int mxt = 1000001;

int r, c, t, d;
vector<vector<int>> mt;

vector<vector<int>> vout;
vector<vector<int>> vin;

struct info {
    int y, x, t;
};

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int cost(int y1, int x1, int y2, int x2) {
    if (mt[y1][x1] >= mt[y2][x2]) return 1;
    else return abs(mt[y1][x1] - mt[y2][x2]) * abs(mt[y1][x1] - mt[y2][x2]);
}

void make_vout() {
    vout.resize(r, vector<int>(c, mxt));
    queue<info> q;
    q.push({0, 0, 0});
    vout[0][0] = 0;
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        if (vout[p.y][p.x] < p.t) continue;
        int ny, nx;
        for (auto i = 0; i < 4; ++i) {
            ny = p.y + dy[i];
            nx = p.x + dx[i];
            if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
            if (abs(mt[p.y][p.x] - mt[ny][nx]) > t) continue;
            if (vout[ny][nx] > vout[p.y][p.x] + cost(p.y, p.x, ny, nx)) {
                vout[ny][nx] = vout[p.y][p.x] + cost(p.y, p.x, ny, nx);
                q.push({ny, nx, vout[ny][nx]});
            }
        }
    }
}

void make_vin(){
    vin.resize(r, vector<int>(c, mxt));
    queue<info> q;
    q.push({0, 0, 0});
    vin[0][0] = 0;
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        if (vin[p.y][p.x] < p.t) continue;
        int ny, nx;
        for (auto i = 0; i < 4; ++i) {
            ny = p.y + dy[i];
            nx = p.x + dx[i];
            if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
            if (abs(mt[p.y][p.x] - mt[ny][nx]) > t) continue;
            if (vin[ny][nx] > vin[p.y][p.x] + cost(ny, nx, p.y, p.x)) {
                vin[ny][nx] = vin[p.y][p.x] + cost(ny, nx, p.y, p.x);
                q.push({ny, nx, vin[ny][nx]});
            }
        }
    }
}

int sol() {
    int ret = 0;

    make_vout();
    make_vin();

    for (auto y = 0; y < r; ++y) {
        for (auto x = 0; x < c; ++x) {
            if (vout[y][x] + vin[y][x] > d) continue;
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