#include <bits/stdc++.h>

using namespace std;

struct node {
    int y, x, h;

    bool operator<(const node &rhs) const {
        return h < rhs.h;
    }

    bool operator>(const node &rhs) const {
        return h > rhs.h;
    }
};

int r, c, h;
vector<vector<int>> hor;
vector<vector<int>> ver;

vector<vector<int>> tank;

void sol(int y, int x, int hh) {
    priority_queue<node, vector<node>, greater<>> pq;
    if (hh < tank[y][x]) {
        tank[y][x] = hh;
        pq.push({y, x, hh});
    }

    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        if (p.h > tank[p.y][p.x]) continue;

        if (hor[p.y][p.x] != -1 && p.y > 0) {
            int pos = max(tank[p.y][p.x], hor[p.y][p.x]);
            if (tank[p.y - 1][p.x] > pos) {
                tank[p.y - 1][p.x] = pos;
                pq.push({p.y - 1, p.x, pos});
            }
        }

        if (ver[p.y][p.x] != -1 && p.x > 0) {
            int pos = max(tank[p.y][p.x], ver[p.y][p.x]);
            if (tank[p.y][p.x - 1] > pos) {
                tank[p.y][p.x - 1] = pos;
                pq.push({p.y, p.x - 1, pos});
            }
        }

        if (hor[p.y + 1][p.x] != -1 && p.y < r - 1) {
            int pos = max(tank[p.y][p.x], hor[p.y + 1][p.x]);
            if (tank[p.y + 1][p.x] > pos) {
                tank[p.y + 1][p.x] = pos;
                pq.push({p.y + 1, p.x, pos});
            }
        }

        if (ver[p.y][p.x + 1] != -1 && p.x < c - 1) {
            int pos = max(tank[p.y][p.x], ver[p.y][p.x + 1]);
            if (tank[p.y][p.x + 1] > pos) {
                tank[p.y][p.x + 1] = pos;
                pq.push({p.y, p.x + 1, pos});
            }
        }
    }
}

int sum() {
    int ret = 0;
    for (auto &rw: tank) {
        ret += accumulate(rw.begin(), rw.end(), 0);
    }
    return ret;
}

int sol() {
    tank.resize(r, vector<int>(c, h));
    for (auto x = 0; x < c; ++x) {
        if (hor[0][x] != -1) sol(0, x, hor[0][x]);
        if (hor[r][x] != -1) sol(r - 1, x, hor[r][x]);
    }

    for (auto y = 0; y < r; ++y) {
        if (ver[y][0] != -1) sol(y, 0, ver[y][0]);
        if (ver[y][c] != -1) sol(y, c - 1, ver[y][c]);
    }

    return sum();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c >> h;
    hor.resize(r + 1, vector<int>(c));
    for (auto &rw: hor) {
        for (auto &el: rw) {
            cin >> el;
        }
    }

    ver.resize(r, vector<int>(c + 1));
    for (auto &rw: ver) {
        for (auto &el: rw) {
            cin >> el;
        }
    }

    cout << sol();

    return 0;
}