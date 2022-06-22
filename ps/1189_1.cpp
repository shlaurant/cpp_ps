#include <bits/stdc++.h>

using namespace std;

void calc_np(const pair<int, int> &p, pair<int, int> (&np)[4]) {
    np[0] = {p.first - 1, p.second};
    np[1] = {p.first, p.second + 1};
    np[2] = {p.first + 1, p.second};
    np[3] = {p.first, p.second - 1};
}

void
dfs(const vector<vector<char>> &m, const pair<int, int> &p,
    vector<vector<bool>> &v, int cnt, int &ret) {
    if (cnt == 1) {
        if (p.first == 0 && p.second == m[0].size() - 1) ++ret;
        return;
    }

    v[p.first][p.second] = true;
    pair<int, int> np[4];
    calc_np(p, np);
    for (const auto &_np: np) {
        if (_np.first < 0 || _np.first >= m.size() || _np.second < 0 ||
            _np.second >= m[0].size())
            continue;
        if (!v[_np.first][_np.second] && m[_np.first][_np.second] == '.')
            dfs(m, _np, v, cnt - 1, ret);
    }
    v[p.first][p.second] = false;

}

int sol(const vector<vector<char>> &m, int k) {
    int ret = 0;
    vector<vector<bool>> v(m.size(), vector<bool>(m[0].size()));

    dfs(m, {m.size() - 1, 0}, v, k, ret);

    return ret;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    int r, c, k;
    cin >> r >> c >> k;
    vector<vector<char>> mp(r, vector<char>(c));

    for (auto &rw: mp) {
        for (auto &el: rw) {
            cin >> el;
        }
    }

    cout << sol(mp, k);
    return 0;
}