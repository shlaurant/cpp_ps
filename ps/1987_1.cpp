#include <bits/stdc++.h>

using namespace std;

int r, c;

void move(pair<int, int> t, pair<int, int> (&np)[4]) {
    np[0] = {t.first - 1, t.second};
    np[1] = {t.first, t.second + 1};
    np[2] = {t.first + 1, t.second};
    np[3] = {t.first, t.second - 1};
}

void dfs(const pair<int, int> &b, int cur, int &ret, bool (&s)[26],
         char (&m)[20][20]) {
    s[m[b.first][b.second] - 'A'] = true;
    ++cur;
    ret = max(ret, cur);

    pair<int, int> _np[4];
    move(b, _np);
    for (const auto &np: _np) {
        if (np.first < 0 || np.first >= r || np.second < 0 ||
            np.second >= c)
            continue;
        if (!s[m[np.first][np.second] - 'A']) {
            dfs(np, cur, ret, s, m);
        }
    }
    s[m[b.first][b.second] - 'A'] = false;
    --cur;
}

int sol(char (&m)[20][20]) {
    int ret = 0;
    int cur = 0;
    bool s[26] = {false,};
    dfs({0, 0}, cur, ret, s, m);
    return ret;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;

    char m[20][20];
    for (auto y = 0; y < r; ++y) {
        for (auto x = 0; x < c; ++x) {
            cin >> m[y][x];
        }
    }

    cout << sol(m);
}