#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> table;

vector<vector<int>> bit;

void update(int r, int c, int val) {
    r += 1;
    c += 1;

    while (r < n + 1) {
        auto _c = c;
        while (_c < n + 1) {
            bit[r][_c] += val;
            _c += _c & -_c;
        }
        r += r & -r;
    }
}

void cons_bit() {
    bit.resize(n + 1, vector<int>(n + 1));

    for (auto y = 0; y < n; ++y) {
        for (auto x = 0; x < n; ++x) {
            update(y, x, table[y][x]);
        }
    }
}

int query(int r, int c) {
    int ret = 0;

    r += 1;
    c += 1;

    while (r > 0) {
        auto _c = c;
        while (_c > 0) {
            ret += bit[r][_c];
            _c -= _c & -_c;
        }
        r -= r & -r;
    }

    return ret;
}

int query(int r1, int c1, int r2, int c2) {
    int ret = query(r2, c2);
    ret -= query(r1 - 1, c2);
    ret -= query(r2, c1 - 1);
    ret += query(r1 - 1, c1 - 1);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    table.resize(n, vector<int>(n));
    for (auto &rw: table) {
        for (auto &el: rw) {
            cin >> el;
        }
    }

    cons_bit();
    for (auto i = 0; i < m; ++i) {
        int w;
        cin >> w;
        if (w == 0) {
            int x, y, c;
            cin >> x >> y >> c;
            update(x - 1, y - 1, c - table[x - 1][y - 1]);
            table[x-1][y-1] = c;
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << query(x1 - 1, y1 - 1, x2 - 1, y2 - 1) << '\n';
        }
    }

    return 0;
}