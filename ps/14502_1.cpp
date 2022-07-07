//1150
#include <bits/stdc++.h>

using namespace std;

int r, c;
vector<vector<int>> lab;

vector<vector<int>> t_lab;
vector<vector<bool>> v_visit;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void _spread(int y, int x) {
    v_visit[y][x] = true;
    t_lab[y][x] = 2;
    for (auto i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
        if (!v_visit[ny][nx] && t_lab[ny][nx] == 0) {
            _spread(ny, nx);
        }
    }
}

void spread() {
    for (auto &rw: v_visit) {
        fill(rw.begin(), rw.end(), false);
    }
    for (auto y = 0; y < r; ++y) {
        for (auto x = 0; x < c; ++x) {
            if (t_lab[y][x] == 2 && !v_visit[y][x]) _spread(y, x);
        }
    }
}

int count() {
    int ret = 0;

    for (const auto &rw: t_lab) {
        for (auto el: rw) {
            if (el == 0) ++ret;
        }
    }

    return ret;
}

void rec(int y, int x, int cnt, int &mx) {
    if (cnt == 3) {
        for (auto i = 0; i < r; ++i) {
            copy(lab[i].begin(), lab[i].end(), t_lab[i].begin());
        }
        spread();
        mx = max(mx, count());
        return;
    }
    if (y < 0 || y >= r || x < 0 || x >= c) return;

    rec(y + (x + 1) / c, (x + 1) % c, cnt, mx);
    if (lab[y][x] == 0) {
        lab[y][x] = 1;
        rec(y + (x + 1) / c, (x + 1) % c, cnt+1, mx);
        lab[y][x] = 0;
    }
}

int sol() {
    t_lab = vector<vector<int>>(lab);
    v_visit.resize(r, vector<bool>(c));
    int ret = 0;

    rec(0, 0, 0, ret);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c;
    lab.resize(r, vector<int>(c));
    for (auto &rw: lab) {
        for (auto &el: rw) {
            cin >> el;
        }
    }

    cout << sol();

    return 0;
}