#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> mp;

int acc_ver(int y, int x, int sz) {
    int s = 0;

    for (auto i = y; i < y + sz; ++i) {
        s += mp[i][x];
    }

    return s;
}

int line_max(int y, int x) {
    int ret = -1;

    if (x + 4 <= m) {
        ret = max(ret, accumulate(mp[y].begin() + x, mp[y].begin() + x + 4, 0));
    }

    if (y + 4 <= n) {
        ret = max(acc_ver(y, x, 4), ret);
    }

    return ret;
}

int box_max(int y, int x) {
    int ret = -1;

    if (y + 2 <= n && x + 2 <= m) {
        int s = 0;
        for (auto i = y; i < y + 2; ++i) {
            s += accumulate(mp[i].begin() + x, mp[i].begin() + x + 2, 0);
        }
        ret = max(ret, s);
    }

    return ret;
}

int l_max(int y, int x) {
    int ret = -1;

    if (y + 3 <= n && x + 2 <= m) {
        ret = max(acc_ver(y, x, 3) + mp[y + 2][x + 1], ret);
        ret = max(acc_ver(y, x, 3) + mp[y][x + 1], ret);
        ret = max(acc_ver(y, x + 1, 3) + mp[y + 2][x], ret);
        ret = max(acc_ver(y, x + 1, 3) + mp[y][x], ret);
    }

    if (y + 2 <= n && x + 3 <= m) {
        ret = max(accumulate(mp[y].begin() + x, mp[y].begin() + x + 3, 0) +
                  max(mp[y + 1][x], mp[y + 1][x + 2]), ret);
        ret = max(accumulate(mp[y + 1].begin() + x, mp[y + 1].begin() + x + 3,
                             0) +
                  max(mp[y][x], mp[y][x + 2]), ret);
    }

    return ret;
}

int z_max(int y, int x) {
    int ret = -1;

    if (y + 3 <= n && x + 2 <= m) {
        ret = max(ret, mp[y + 1][x] + mp[y + 1][x + 1] +
                       max(mp[y][x] + mp[y + 2][x + 1],
                           mp[y][x + 1] + mp[y + 2][x]));
    }

    if (y + 2 <= n && x + 3 <= m) {
        ret = max(ret, mp[y][x + 1] + mp[y + 1][x + 1] +
                       max(mp[y][x] + mp[y + 1][x + 2],
                           mp[y + 1][x] + mp[y][x + 2]));
    }

    return ret;
}

int t_max(int y, int x) {
    int ret = -1;

    if (y + 2 <= n && x + 3 <= m) {
        ret = max(ret,
                  mp[y][x] + mp[y][x + 1] + mp[y][x + 2] + mp[y + 1][x + 1]);
        ret = max(ret,
                  mp[y + 1][x] + mp[y + 1][x + 1] + mp[y + 1][x + 2] +
                  mp[y][x + 1]);
    }

    if (y + 3 <= n && x + 2 <= m) {
        ret = max(ret, acc_ver(y, x, 3) + mp[y + 1][x + 1]);
        ret = max(ret, acc_ver(y, x + 1, 3) + mp[y + 1][x]);
    }

    return ret;
}

int sol() {
    int ret = -1;

    for (auto i = 0; i < n; ++i) {
        for (auto j = 0; j < m; ++j) {
            ret = max(ret, line_max(i, j));
            ret = max(ret, box_max(i, j));
            ret = max(ret, l_max(i, j));
            ret = max(ret, z_max(i, j));
            ret = max(ret, t_max(i, j));
        }
    }

    return ret;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    mp.resize(n, vector<int>(m));
    for (auto &rw: mp) {
        for (auto &el: rw) {
            cin >> el;
        }
    }

    cout << sol();

    return 0;
}