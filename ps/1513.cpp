#include <bits/stdc++.h>

using namespace std;

int n, m, c;
vector<vector<int>> mp;

int dp[50][50][51][51];
vector<int> ans;

void init() {
    for (auto &rw: dp[0][0]) {
        for (auto &el: rw) {
            el = 0;
        }
    }
    if (mp[0][0] == 0) {
        for (auto &el: dp[0][0][0]) {
            el = 1;
        }
    } else {
        for (auto i = mp[0][0]; i <= c; ++i) {
            dp[0][0][1][i] = 1;
        }
    }
}

bool oob(int i) { return i < 0 || i > c; }

bool out_of_bound(int y, int x) { return y < 0 || y >= n || x < 0 || x >= m; }

int look_up(int y, int x, int cnt, int num) {
    if (out_of_bound(y, x) || oob(cnt) || oob(num)) {
        string str;
        str.append(to_string(y));
        str.append(", ");
        str.append(to_string(x));
        str.append(", ");
        str.append(to_string(cnt));
        str.append(", ");
        str.append(to_string(num));
        throw domain_error(str);
    }

    if (dp[y][x][cnt][num] != -1) return dp[y][x][cnt][num];

    int val = 0;

    if (mp[y][x] == 0) {
        if (!out_of_bound(y - 1, x)) val += look_up(y - 1, x, cnt, num);
        if (!out_of_bound(y, x - 1)) val += look_up(y, x - 1, cnt, num);
    } else if (cnt > 0 && mp[y][x] <= num) {
        if (!out_of_bound(y - 1, x))
            val += look_up(y - 1, x, cnt - 1, mp[y][x]);
        if (!out_of_bound(y, x - 1))
            val += look_up(y, x - 1, cnt - 1, mp[y][x]);
    }

    dp[y][x][cnt][num] = val% 1000007;
    return dp[y][x][cnt][num];
}


void sol() {
    fill((&dp)[0][0][0][0], (&dp)[0][0][0][0] + 2500 * 51 * 51, -1);
    init();
    for (auto i = 0; i <= c; ++i) {
        ans.push_back(look_up(n - 1, m - 1, i, c) % 1000007);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> c;
    mp.resize(n, vector<int>(m));
    for (auto i = 0; i < c; ++i) {
        int y, x;
        cin >> y >> x;
        mp[y - 1][x - 1] = i + 1;
    }

    sol();

    for (auto el: ans) {
        cout << el << ' ';
    }

    return 0;
}