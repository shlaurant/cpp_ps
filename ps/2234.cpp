#include <bits/stdc++.h>

using namespace std;

int c, r;
vector<vector<int>> mp;

int ans1;
int ans2;
int ans3;

vector<int> rooms;
vector<vector<int>> v;

pair<int, int> next_of(int y, int x, int i) {
    switch (i) {
        case 0:
            return {y, x - 1};
        case 1:
            return {y - 1, x};
        case 2:
            return {y, x + 1};
        case 3:
            return {y + 1, x};
        default:
            throw domain_error("ee");
    }
}

int dfs(int y, int x, int r_no) {
    int ret = 1;

    v[y][x] = r_no;
    for (auto i = 0; i < 4; ++i) {
        if (!(mp[y][x] & 1 << i)) {
            auto nyx = next_of(y, x, i);
            if (nyx.first < 0 || nyx.first >= r || nyx.second < 0 ||
                nyx.second >= c)
                continue;
            if (v[nyx.first][nyx.second] != -1) continue;
            ret += dfs(nyx.first, nyx.second, r_no);
        }
    }

    return ret;
}

int max_room() {
    int ret = INT_MIN;

    for (auto el: rooms) {
        ret = max(ret, el);
    }

    return ret;
}

int sol3() {
    int ret = INT_MIN;

    for (auto y = 0; y < r; ++y) {
        for (auto x = 0; x < c; ++x) {
            for (auto i = 0; i < 4; ++i) {
                if(mp[y][x] & 1 << i){
                    int ny, nx;
                    tie(ny, nx) = next_of(y, x, i);
                    if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
                    if (v[ny][nx] != v[y][x])
                        ret = max(rooms[v[y][x]] + rooms[v[ny][nx]], ret);
                }
            }
        }
    }

    return ret;
}

void sol() {
    v.resize(mp.size(), vector<int>(mp[0].size(), -1));

    int r_no = 0;
    for (auto i = 0; i < c * r; ++i) {
        if (v[i / c][i % c] == -1) {
            auto sz = dfs(i / c, i % c, r_no);
            rooms.push_back(sz);
            ++r_no;
        }
    }

    ans1 = rooms.size();
    ans2 = max_room();
    ans3 = sol3();

    return;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> c >> r;
    mp.resize(r, vector<int>(c));

    for (auto &rw: mp) {
        for (auto &el: rw) {
            cin >> el;
        }
    }

    sol();

    cout << ans1 << '\n' << ans2 << '\n' << ans3;

    return 0;
}