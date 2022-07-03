#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> *room;

vector<vector<vector<int>>> dp;

bool possible(int y, int x, int dir) {
    vector<pair<int, int>> pv;
    pv.push_back({y, x});
    switch (dir) {
        case 0:
            pv.push_back({y, x - 1});
            break;
        case 1:
            pv.push_back({y - 1, x});
            break;
        case 2:
            pv.push_back({y, x - 1});
            pv.push_back({y - 1, x});
            pv.push_back({y - 1, x - 1});
            break;
    }
    for(const auto &el:pv){
        if(el.first < 0 || el.first >= n || el.second < 0 || el.second >= n)
            return false;
        if((*room)[el.first][el.second] == 1) return false;
    }
    return true;
}

int look_up(int y, int x, int dir) {
    if (dp[y][x][dir] != -1) return dp[y][x][dir];
    if (!possible(y, x, dir)) {
        dp[y][x][dir] = 0;
        return 0;
    }

    int val = 0;
    switch (dir) {
        case 0:
            if (possible(y, x - 1, dir))val += look_up(y, x - 1, dir);
            if (possible(y, x - 1, 2))val += look_up(y, x - 1, 2);
            break;
        case 1:
            if (possible(y - 1, x, dir))val += look_up(y - 1, x, dir);
            if (possible(y - 1, x, 2))val += look_up(y - 1, x, 2);
            break;
        case 2:
            if (possible(y - 1, x - 1, 0))val += look_up(y - 1, x - 1, 0);
            if (possible(y - 1, x - 1, 1))val += look_up(y - 1, x - 1, 1);
            if (possible(y - 1, x - 1, 2))val += look_up(y - 1, x - 1, 2);
            break;
    }
    dp[y][x][dir] = val;
    return val;
}

int sol() {
    dp.resize(n, vector<vector<int>>(n, vector<int>(3, -1)));
    dp[0][1][0] = 1;
    return look_up(n - 1, n - 1, 0) + look_up(n - 1, n - 1, 1) +
           look_up(n - 1, n - 1, 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    room = new vector<vector<int>>(n, vector<int>(n));
    for (auto &rw: *room) {
        for (auto &el: rw) {
            cin >> el;
        }
    }

    cout << sol();

    delete room;

    return 0;
}