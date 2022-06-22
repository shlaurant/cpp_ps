#include <bits/stdc++.h>

using namespace std;

int dy[] = {-1, -2, -1, 0, 0, 1, 1, 2, 1, 0, 0, -1};
int dx[] = {0, 0, 1, 1, 2, 1, 0, 0, -1, -1, -2, -1};

void np_of(const pair<int, int> &p, pair<int, int> (&np)[4]) {
    np[0] = {p.first - 1, p.second};
    np[1] = {p.first, p.second + 1};
    np[2] = {p.first + 1, p.second};
    np[3] = {p.first, p.second - 1};
}

void calc_g(const vector<vector<int>> &ori, vector<vector<int>> &res) {
    pair<int, int> np[4];

    unsigned long long int n = ori.size();
    for (auto y = 0; y < n; ++y) {
        for (auto x = 0; x < n; ++x) {
            int sum = ori[y][x];
            np_of({y, x}, np);
            for (const auto &_np: np) {
                if (_np.first < 0 || _np.first >= n || _np.second < 0 ||
                    _np.second >= n) {
                    sum = INT_MAX;
                    break;
                }
                sum += ori[_np.first][_np.second];
            }
            res[y][x] = sum;
        }
    }
}

bool is_val(int y, int x, int n) {
    return y >= 0 && y < n && x >= 0 && x < n;
}

void do_visit(vector<vector<int>> &visit, int y, int x) {
    ++visit[y][x];
    int ny, nx;
    for (auto i = 0; i < 12; ++i) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (is_val(ny, nx, visit.size())) ++visit[ny][nx];
    }
}

void undo_visit(vector<vector<int>> &visit, int y, int x) {
    --visit[y][x];
    int ny, nx;
    for (auto i = 0; i < 12; ++i) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (is_val(ny, nx, visit.size())) --visit[ny][nx];
    }
}

void dfs(vector<vector<int>> &visit, const vector<vector<int>> &g,
         const pair<int, int> &b, int cnt, int cur, int &ret) {
    int n = visit.size();

    if (cnt == 0) ret = min(cur, ret);
    if (b.first == visit.size() - 1) return;
    if (ret <= cur) return;
    if (b.second >= n) dfs(visit, g, {b.first + 1, 0}, cnt, cur, ret);


    for (auto y = b.first; y < n; ++y) {
        for (auto x = 0; x < n; ++x) {
            if (visit[y][x]) continue;
            do_visit(visit, y, x);
            dfs(visit, g, {b.first, b.second + 1}, cnt - 1, cur + g[y][x], ret);
            undo_visit(visit, y, x);
        }
    }
}

int sol(int n, const vector<vector<int>> &g) {
    int ret = INT_MAX;
    vector<int> t(n);
    t[0] = 1; t[n-1] = 1;
    vector<vector<int>> visit(n, t);
    vector<vector<int>> _g(n, vector<int>(n, INT_MAX));

    fill(visit[0].begin(), visit[0].end(), 1);
    fill(visit[n-1].begin(), visit[n-1].end(), 1);

    calc_g(g, _g);
    dfs(visit, _g, {0, 0}, 3, 0, ret);

    return ret;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    for (auto &r: g) {
        for (auto &e: r) {
            cin >> e;
        }
    }

    cout << sol(n, g);
}