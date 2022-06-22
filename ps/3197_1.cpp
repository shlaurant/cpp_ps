#include <bits/stdc++.h>

using namespace std;

int r, c;
vector<vector<char>> lake;

vector<vector<bool>> v, iv;
vector<pair<int, int>> spos;

void find_swan() {

    for (auto i = 0; i < r; ++i) {
        for (auto j = 0; j < c; ++j) {
            if (lake[i][j] == 'L') {
                spos.push_back({i, j});
            }
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

void bfs(queue<pair<int, int>> &q, vector<vector<bool>> &v) {
    queue<pair<int, int>> temp;
    pair<int, int> np[4];
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        make_move(cur, np);
        for (const auto &el: np) {
            if (over_bound(el)) continue;
            if (!v[el.first][el.second] && lake[el.first][el.second] != 'X') {
                v[el.first][el.second] = true;
                q.push(el);
            } else if (!v[el.first][el.second] &&
                       lake[el.first][el.second] == 'X') {
                v[el.first][el.second] = true;
                temp.push(el);
            }
        }
    }
    swap(temp, q);
}

bool is_met() {
    return v[spos[1].first][spos[1].second];
}

void melt(queue<pair<int, int>> &iq) {
    queue<pair<int, int>> temp;
    pair<int, int> np[4];

    while (!iq.empty()) {
        auto cur = iq.front();
        iq.pop();
        lake[cur.first][cur.second] = '.';
        make_move({cur.first, cur.second}, np);
        for (const auto &el: np) {
            if (over_bound(el)) continue;
            if (lake[el.first][el.second] == 'X' && !iv[el.first][el.second]) {
                temp.push(el);
                iv[el.first][el.second] = true;
            }
        }
    }

    swap(iq, temp);
}

void q_ice(queue<pair<int, int>> &iq) {
    pair<int, int> np[4];
    for (auto i = 0; i < r; ++i) {
        for (auto j = 0; j < c; ++j) {
            if (lake[i][j] != 'X') continue;
            make_move({i, j}, np);
            for (auto &el: np) {
                if (over_bound(el)) continue;
                if (lake[el.first][el.second] != 'X') {
                    iq.push({i, j});
                    iv[i][j] = true;
                    break;
                }
            }
        }
    }
}

queue<pair<int, int>> q1, q2, iq;
int sol() {
    int ret = 0;

    v.resize(r, vector<bool>(c));
    iv.resize(r, vector<bool>(c));
    find_swan();
    q1.push(spos[0]);
    v[spos[0].first][spos[0].second];
    q_ice(iq);

    while (true) {
        bfs(q1, v);
        if (is_met()) break;
        melt(iq);
        ++ret;
    }

    return ret;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c;
    lake.resize(r, vector<char>(c));
    for (auto &rw: lake) {
        for (auto &el: rw) {
            cin >> el;
        }
    }

    cout << sol();

    return 0;
}