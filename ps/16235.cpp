#include <bits/stdc++.h>

using namespace std;

struct sq {
    int nut = 5;
    deque<int> trees;
};

int n, m, k;
vector<vector<int>> a;

vector<vector<sq>> land;

void ss(sq &e) {
    auto it = e.trees.begin();
    while (it != e.trees.end()) {
        if (e.nut < *it) {
            break;
        }
        e.nut -= *it;
        *it += 1;
        ++it;
    }

    auto b = it;
    while (it != e.trees.end()) {
        e.nut += *it / 2;
        ++it;
    }
    e.trees.erase(b, it);
}

bool out_bound(int y, int x) {
    return y < 0 || y >= n || x < 0 || x >= n;
}

pair<int, int> dp[] = {{-1, 0},
                       {0,  1},
                       {1,  0},
                       {0,  -1},
                       {-1, -1},
                       {-1, 1},
                       {1,  1},
                       {1,  -1}};

void breed(int y, int x) {
    auto &el = land[y][x];
    auto it = el.trees.begin();
    while (it != el.trees.end()) {
        if (*it % 5 == 0) {
            int ny, nx;
            for (const auto &_dp: dp) {
                ny = y + _dp.first;
                nx = x + _dp.second;
                if (out_bound(ny, nx)) continue;
                land[ny][nx].trees.push_front(1);
            }
        }
        ++it;
    }
}

void age() {
    for (auto &rw: land) {
        for (auto &el: rw) {
            ss(el);
        }
    }
    for (auto y = 0; y < n; ++y) {
        for (auto x = 0; x < n; ++x) {
            breed(y, x);
            land[y][x].nut += a[y][x];
        }
    }
}

int sum() {
    int ret = 0;

    for (const auto &rw: land) {
        for (const auto &el: rw) {
            ret += el.trees.size();
        }
    }

    return ret;
}

int sol() {
    for (auto i = 0; i < k; ++i) {
        age();
    }
    return sum();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    a.resize(n, vector<int>(n));
    for (auto &rw: a) {
        for (auto &el: rw) {
            cin >> el;
        }
    }

    land.resize(n, vector<sq>(n));
    for (auto i = 0; i < m; ++i) {
        int y, x, q;
        cin >> y >> x >> q;
        land[y - 1][x - 1].trees.push_back(q);
    }

    cout << sol();

    return 0;
}