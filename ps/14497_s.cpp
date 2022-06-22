#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> np_of(const pair<int, int> &cp) {
    vector<pair<int, int>> ret;

    ret.push_back({cp.first - 1, cp.second});
    ret.push_back({cp.first, cp.second + 1});
    ret.push_back({cp.first + 1, cp.second});
    ret.push_back({cp.first, cp.second - 1});

    return ret;
}

void search(vector<vector<char>> &m, vector<vector<int>> &v,
            queue<pair<int, int>> &cur, queue<pair<int, int>> &next) {
    while (!cur.empty()) {
        auto cp = cur.front();
        cur.pop();
        for (const auto &np: np_of(cp)) {
            if (np.first < 0 || np.first >= m.size() || np.second < 0 ||
                np.second >= m[0].size())
                continue;
            if (!v[np.first][np.second]) {
                if (m[np.first][np.second] == '1' ||
                    m[np.first][np.second] == '#') {
                    m[np.first][np.second] = '0';
                    v[np.first][np.second] = v[cp.first][cp.second] + 1;
                    next.push(np);
                } else {
                    v[np.first][np.second] = v[cp.first][cp.second];
                    cur.push(np);
                }
            }
        }
    }
}

vector<vector<int>>
bfs(vector<vector<char>> &m, const pair<int, int> &b, const pair<int, int> &e) {
    vector<vector<int>> visit(m.size(), vector<int>(m[0].size()));
    queue<pair<int, int>> q;
    queue<pair<int, int>> p;

    q.push(b);
    visit[b.first][b.second] = 1;

    while (!q.empty() || visit[e.first][e.second] == 0) {
        search(m, visit, q, p);
        if (p.empty() || visit[e.first][e.second] != 0) break;
        search(m, visit, p, q);
    }
    return visit;
}

int sol(const pair<int, int> &size, const pair<int, int> &b,
        const pair<int, int> &e, vector<vector<char>> &m) {
    return bfs(m, b, e)[e.first][e.second] - 1;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, y1, x1, y2, x2;
    cin >> n >> m >> y1 >> x1 >> y2 >> x2;

    vector<vector<char>> mp(n, vector<char>(m));
    for (auto &r: mp) {
        for (auto &c: r) {
            cin >> c;
        }
    }

    cout << sol({n, m}, {y1 - 1, x1 - 1}, {y2 - 1, x2 - 1}, mp);
}