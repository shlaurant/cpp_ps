#include <bits/stdc++.h>

using namespace std;

int r, c, t;
vector<vector<int>> room;
vector<vector<int>> temp_room;

queue<pair<int, int>> dust_q;
vector<pair<int, int>> cleaner;

void queue_dust() {
    for (auto i = 0; i < r; ++i) {
        for (auto j = 0; j < c; ++j) {
            if (room[i][j] > 0) dust_q.push({i, j});
        }
    }
}

void make_move(const pair<int, int> &p, pair<int, int> (&np)[4]) {
    np[0] = {p.first - 1, p.second};
    np[1] = {p.first, p.second + 1};
    np[2] = {p.first + 1, p.second};
    np[3] = {p.first, p.second - 1};
}

bool over_bound(const pair<int, int> &p) {
    return p.first < 0 || p.first >= r || p.second < 0 || p.second >= c;
}

void do_spread(const pair<int, int> &p) {
    pair<int, int> np[4];
    make_move(p, np);
    int cnt = 0;

    for (const auto &el: np) {
        if (over_bound(el)) continue;
        if (room[el.first][el.second] == -1) continue;
        temp_room[el.first][el.second] += room[p.first][p.second] / 5;
        ++cnt;
    }

    temp_room[p.first][p.second] +=
            room[p.first][p.second] - (room[p.first][p.second] / 5) * cnt;
}

void spread_dust() {
    for (auto &rw: temp_room) {
        fill(rw.begin(), rw.end(), 0);
    }
    queue_dust();

    while (!dust_q.empty()) {
        do_spread(dust_q.front());
        dust_q.pop();
    }
    for (auto y = 0; y < r; ++y) {
        for (auto x = 0; x < c; ++x) {
            if (room[y][x] != -1) {
                room[y][x] = temp_room[y][x];
            }
        }
    }
}

void find_cleaner() {
    for (auto i = 0; i < r; ++i) {
        for (auto j = 0; j < c; ++j) {
            if (room[i][j] == -1) cleaner.push_back({i, j});
        }
    }
}

void move_ver(const pair<int, int> &b, const pair<int, int> &e, int dir) {
    for (auto y = b.first; y != e.first; y += dir) {
        int ori = room[y + dir][b.second];
        room[y + dir][b.second] = 0;
        if (room[y][b.second] != -1) room[y][b.second] = ori;
    }
}

void move_hor(const pair<int, int> &b, const pair<int, int> &e, int dir) {
    int y = b.first;
    for (auto x = b.second; x != e.second; x += dir) {
        int ori = room[y][x + dir];
        if (ori != -1) {
            room[y][x + dir] = 0;
            room[y][x] = ori;
        }
    }
}

void activate_cleaner() {
    move_ver({cleaner[0].first, 0}, {0, 0}, -1);
    move_hor({0, 0}, {0, c - 1}, 1);
    move_ver({0, c - 1}, {cleaner[0].first, c - 1}, 1);
    move_hor({cleaner[0].first, c - 1}, {cleaner[0].first, 0}, -1);

    move_ver({cleaner[1].first, 0}, {r - 1, 0}, 1);
    move_hor({r - 1, 0}, {r - 1, c - 1}, 1);
    move_ver({r - 1, c - 1}, {cleaner[1].first, c - 1}, -1);
    move_hor({cleaner[1].first, c - 1}, {cleaner[1].first, 0}, -1);
}

int total_dust() {
    int sum = 0;

    for (const auto &rw: room) {
        for (auto el: rw) {
            sum += el;
        }
    }

    return sum + 2;
}

int sol() {
    find_cleaner();
    temp_room.resize(r, vector<int>(c));

    for (auto i = 0; i < t; ++i) {
        spread_dust();
        activate_cleaner();
    }
    return total_dust();
}

int main() {
    std::ios_base::sync_with_stdio(false);
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