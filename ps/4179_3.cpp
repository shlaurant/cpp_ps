#include <bits/stdc++.h>

using namespace std;

int r, c;
vector<vector<char>> room;

pair<int, int> j;
queue<pair<int, int>> fq;

vector<vector<int>> visit;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void spread_fire() {
    queue<pair<int, int>> temp;
    while (!fq.empty()) {
        auto p = fq.front();
        fq.pop();
        for (auto i = 0; i < 4; ++i) {
            int ny = p.first + dy[i];
            int nx = p.second + dx[i];
            if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;

            if (room[ny][nx] != 'F' && room[ny][nx] != '#') {
                room[ny][nx] = 'F';
                temp.push({ny, nx});
            }
        }
    }
    swap(temp, fq);
}

void search_once(queue<pair<int, int>> &q) {
    queue<pair<int, int>> temp;
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        for (auto i = 0; i < 4; ++i) {
            int ny = p.first + dy[i];
            int nx = p.second + dx[i];
            if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;

            if (visit[ny][nx] == 0 && room[ny][nx] == '.') {
                visit[ny][nx] = visit[p.first][p.second] + 1;
                temp.push({ny, nx});
            }
        }
    }
    swap(temp, q);
}

int find_min() {
    int ret = INT_MAX;
    for (auto el: visit[0]) {
        if (el > 0) ret = min(ret, el);
    }
    for (auto el: visit[r-1]) {
        if (el > 0) ret = min(ret, el);
    }
    for(auto i = 0; i < r; ++i){
        if(visit[i][0] > 0) ret = min(ret, visit[i][0]);
        if(visit[i][c-1] > 0) ret = min(ret, visit[i][c-1]);
    }

    return ret == INT_MAX ? -1 : ret;
}

int sol() {
    visit.resize(r, vector<int>(c));
    queue<pair<int, int>> jq;
    visit[j.first][j.second] = 1;
    jq.push(j);

    while (!jq.empty()) {
        spread_fire();
        search_once(jq);
    }

    return find_min();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c;
    room.resize(r, vector<char>(c));
    for (auto y = 0; y < r; ++y) {
        for (auto x = 0; x < c; ++x) {
            cin >> room[y][x];
            if (room[y][x] == 'J') j = {y, x};
            if (room[y][x] == 'F') fq.push({y, x});
        }
    }

    auto s = sol();
    s == -1 ? cout << "IMPOSSIBLE" : cout << s;

    return 0;
}