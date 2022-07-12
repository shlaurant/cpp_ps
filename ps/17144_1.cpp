//2005
#include <bits/stdc++.h>

using namespace std;

int r, c, t;
vector<vector<int>> room;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

pair<int, int> ac[2];

void _spread(int y, int x, vector<vector<int>> &temp) {
    if (room[y][x] == -1) {
        temp[y][x] = -1;
        return;
    }

    int cnt = 0;
    for (auto i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
        if (room[ny][nx] == -1) continue;
        temp[ny][nx] += room[y][x] / 5;
        ++cnt;
    }
    temp[y][x] += room[y][x] - (room[y][x] / 5) * cnt;
}

void spread() {
    vector<vector<int>> temp;
    temp.resize(r, vector<int>(c));
    for (auto y = 0; y < r; ++y) {
        for (auto x = 0; x < c; ++x) {
            _spread(y, x, temp);
        }
    }

    for (auto i = 0; i < r; ++i) {
        copy(temp[i].begin(), temp[i].end(), room[i].begin());
    }
}

void find_ac() {
    auto index = 0;
    for (auto i = 0; i < r; ++i) {
        if (room[i][0] == -1) {
            ac[index] = {i, 0};
            ++index;
        }
    }
}

pair<int, int> p0[] = {{0,  1},
                       {-1, 0},
                       {0,  -1},
                       {1,  0}};
int cp0 = 0;
pair<int, int> nextp0(const pair<int, int> &p) {
    pair<int, int> np;
    while (true) {
        np = {p.first + p0[cp0].first, p.second + p0[cp0].second};
        int ny, nx;
        tie(ny, nx) = np;
        if (ny < 0 || ny >= r || nx < 0 || nx >= c) ++cp0;
        else break;
    }
    return np;
}

pair<int, int> p1[] = {{0,  1},
                       {1,  0},
                       {0,  -1},
                       {-1, 0}};
int cp1 = 0;
pair<int, int> nextp1(const pair<int, int> &p) {
    pair<int, int> np;
    while (true) {
        np = {p.first + p1[cp1].first, p.second + p1[cp1].second};
        int ny, nx;
        tie(ny, nx) = np;
        if (ny < 0 || ny >= r || nx < 0 || nx >= c) ++cp1;
        else break;
    }
    return np;
}

void work() {
    cp0 = 0;
    cp1 = 0;
    pair<int, int> cur = ac[0];
    ++cur.second;
    auto dust = room[cur.first][cur.second];
    room[cur.first][cur.second] = 0;

    while (true) {
        auto np = nextp0(cur);
        if (np == ac[0]) break;
        auto temp = room[np.first][np.second];
        room[np.first][np.second] = dust;
        dust = temp;
        cur = np;
    }

    cur = ac[1];
    ++cur.second;
    dust = room[cur.first][cur.second];
    room[cur.first][cur.second] = 0;

    while (true) {
        auto np = nextp1(cur);
        if (np == ac[1]) break;
        auto temp = room[np.first][np.second];
        room[np.first][np.second] = dust;
        dust = temp;
        cur = np;
    }
}

int sum() {
    int ret = 0;
    for (auto &rw: room) {
        ret += accumulate(rw.begin(), rw.end(), 0);
    }
    ret += 2;
    return ret;
}

int sol() {
    find_ac();
    for (auto i = 0; i < t; ++i) {
        spread();
        work();
    }
    return sum();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c >> t;
    room.resize(r, vector<int>(c));
    for (auto &rw: room) {
        for (auto &el: rw) {
            cin >> el;
        }
    }

    cout << sol();

    return 0;
}