#include <bits/stdc++.h>

using namespace std;

int r, c;

vector<pair<int, int>> move(pair<int, int> t) {
    vector<pair<int, int>> ret(4);
    ret[0] = {t.first - 1, t.second};
    ret[1] = {t.first, t.second + 1};
    ret[2] = {t.first + 1, t.second};
    ret[3] = {t.first, t.second - 1};
    return ret;
}

void dfs(const pair<int, int> &b, int cur, int &ret, vector<bool> &s,
         const vector<vector<char>> &m) {
//    s[m[b.first][b.second] - 'A'] = true;
//    ++cur;
    ret = max(ret, cur);

    for (const auto &np: move(b)) {
        if (np.first < 0 || np.first >= r || np.second < 0 ||
            np.second >= c)
            continue;
        if (!s[m[np.first][np.second] - 'A']) {
            s[m[b.first][b.second] - 'A'] = true;
            dfs(np, cur + 1, ret, s, m);
            s[m[b.first][b.second] - 'A'] = false;
        }
    }
//    s[m[b.first][b.second] - 'A'] = false;
//    --cur;
}

int sol(vector<vector<char>> &m) {
    int ret = 0;
    int cur = 0;
    vector<bool> s(26);
    dfs({0, 0}, cur, ret, s, m);
    return ret;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;

    vector<vector<char>> m(r, vector<char>(c));
    for (auto &rw: m) {
        for (auto &el: rw) {
            cin >> el;
        }
    }

    cout << sol(m);
}