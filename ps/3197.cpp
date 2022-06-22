#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> np_of(const pair<int, int> p) {
    vector<pair<int, int>> ret(4);
    ret[0] = {p.first - 1, p.second};
    ret[1] = {p.first, p.second + 1};
    ret[2] = {p.first + 1, p.second};
    ret[3] = {p.first, p.second - 1};
    return ret;
}

void melt_ice(vector<vector<char>> &lake, vector<vector<int>> &visit,
              queue<pair<int, int>> &q) {
    queue<pair<int, int>> temp;
    while (!q.empty()) {
        auto cp = q.front();
        q.pop();
        for (const auto &np: np_of(cp)) {
            if (np.first < 0 || np.first >= lake.size() || np.second < 0 ||
                np.second >= lake[0].size())
                continue;
            if (visit[np.first][np.second] == 0 ||
                lake[np.first][np.second] == 'X') {
                temp.push(np);
                visit[np.first][np.second] = 1;
                lake[np.first][np.second] = '.';
            }
        }
    }
    while (!temp.empty()) {
        q.push(temp.front());
        temp.pop();
    }
}

void bfs(vector<vector<char>> &lake, vector<vector<int>> &visit,
         queue<pair<int, int>> &q) {
    queue<pair<int, int>> temp;
    while (!q.empty()) {
        auto cp = q.front();
        q.pop();
        for (const auto &np: np_of(cp)) {
            if (np.first < 0 || np.first >= lake.size() || np.second < 0 ||
                np.second >= lake[0].size())
                continue;
            if (visit[np.first][np.second] == 0) {
                if (lake[np.first][np.second] == 'X') {
                    visit[np.first][np.second] =
                            visit[cp.first][cp.second] + 1;
                    temp.push(np);
                } else {
                    visit[np.first][np.second] = visit[cp.first][cp.second];
                    q.push(np);
                }
            }
        }
    }
    while (!temp.empty()) {
        q.push(temp.front());
        temp.pop();
    }
}

int sol(vector<vector<char>> &lake) {
    vector<vector<int>> visit(lake.size(), vector<int>(lake[0].size()));
    vector<vector<int>> v_ice(visit);

    pair<int, int> arr[2];
    int i = 0;

    queue<pair<int, int>> swan_q, water_q;
    for (auto r = 0; r < lake.size(); ++r) {
        for (auto c = 0; c < lake[0].size(); ++c) {
            if (lake[r][c] == 'L') {
                arr[i] = {r, c};
                water_q.push({r, c});
                v_ice[r][c] = 1;
                ++i;
            } else if (lake[r][c] == '.') {
                water_q.push({r, c});
                v_ice[r][c] = 1;
            }
        }
    }

    swan_q.push(arr[0]);
    visit[arr[0].first][arr[0].second] = 1;


    while (visit[arr[1].first][arr[1].second] == 0) {
        bfs(lake, visit, swan_q);
        if (visit[arr[1].first][arr[1].second] != 0) break;
        melt_ice(lake, v_ice, water_q);
    }

    return --visit[arr[1].first][arr[1].second];
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    int r, c;
    cin >> r >> c;

    vector<vector<char>> lake(r, vector<char>(c));
    for (auto &row: lake) {
        for (auto &col: row) {
            cin >> col;
        }
    }

    cout << sol(lake);
}