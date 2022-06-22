#include <bits/stdc++.h>

using namespace std;

int r, c;
vector<vector<char>> maze;

vector<vector<int>> visit;
vector<vector<int>> f_visit;

int ans = -1;
pair<int, int> sp;
queue<pair<int, int>> fire;

bool in_border(const pair<int, int> &_np);
void trans(queue<pair<int, int>> &src, queue<pair<int, int>> &dest) {
    while (!src.empty()) {
        dest.push(src.front());
        src.pop();
    }
}

void make_move(pair<int, int> p, pair<int, int> (&np)[4]) {
    np[0] = {p.first - 1, p.second};
    np[1] = {p.first, p.second + 1};
    np[2] = {p.first + 1, p.second};
    np[3] = {p.first, p.second - 1};
}

void spread_fire() {
    queue<pair<int, int>> temp;
    while (!fire.empty()) {
        auto cur = fire.front();
        fire.pop();

        pair<int, int> np[4];
        make_move(cur, np);
        for (const auto &_np: np) {
            if (_np.first < 0 || _np.first >= r || _np.second < 0 ||
                _np.second >= c)
                continue;
            if (!f_visit[_np.first][_np.second] &&
                maze[_np.first][_np.second] != '#') {
                f_visit[_np.first][_np.second] = 1;
                temp.push(_np);
            }
        }
    }
    trans(temp, fire);
}

int bfs() {
    if (in_border(sp)) return 1;
    queue<pair<int, int>> q;
    q.push(sp);
    visit[sp.first][sp.second] = 1;

    while (true) {
        queue<pair<int, int>> temp;
        spread_fire();
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            pair<int, int> np[4];
            make_move(cur, np);
            for (const auto &_np: np) {
                if (_np.first < 0 || _np.first >= r || _np.second < 0 ||
                    _np.second >= c)
                    continue;
                if (!visit[_np.first][_np.second] &&
                    maze[_np.first][_np.second] == '.' &&
                    !f_visit[_np.first][_np.second]) {
                    visit[_np.first][_np.second] =
                            visit[cur.first][cur.second] + 1;
                    temp.push(_np);
                    if (in_border(_np))
                        return visit[_np.first][_np.second];
                }
            }
        }
        if (temp.empty()) break;
        trans(temp, q);
    }
    return -1;
}

bool in_border(const pair<int, int> &_np) {
    return _np.first == 0 || _np.first == r - 1 ||
           _np.second == 0 || _np.second == c - 1;
}

void sol() {
    visit.resize(r, vector<int>(c));
    f_visit.resize(r, vector<int>(c));

    for (auto y = 0; y < r; ++y) {
        for (auto x = 0; x < c; ++x) {
            if (maze[y][x] == 'J') sp = {y, x};
            if (maze[y][x] == 'F') {
                fire.push({y, x});
                f_visit[y][x] = 1;
            }
        }
    }


    ans = bfs();
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;

    maze.resize(r, vector<char>(c));

    for (auto &rw: maze) {
        for (auto &el: rw) {
            cin >> el;
        }
    }

    sol();

    ans == -1 ? cout << "IMPOSSIBLE" : cout << ans;

    return 0;
}