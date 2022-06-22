#include <bits/stdc++.h>

using namespace std;

int n, m;
int t[50][50];

vector<pair<int, int>> h;
vector<pair<int, int>> c;
vector<pair<int, int>> cc;

int ans = INT_MAX;

void go2() {
    int cur = 0;
    for (const auto &p: h) {
        int mn = INT_MAX;
        for (const auto &q: cc) {
            mn = min(mn, abs(q.first - p.first) + abs(q.second - p.second));
        }
        cur += mn;
        if (cur >= ans) return;
    }
    ans = min(cur, ans);
}

void dfs2(int b, int cnt) {
    if (cnt == 0) {
        go2();
        return;
    }
    if (b >= c.size()) {
        return;
    }

    for (auto i = b; i < c.size(); ++i) {
        cc.push_back(c[i]);
        --cnt;
        dfs2(i+1, cnt);
        cc.erase(--cc.end());
        ++cnt;
    }
    return;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (auto i = 0; i < n * n; ++i) {
        cin >> t[i / n][i % n];
        if (t[i / n][i % n] == 1) h.push_back({i / n, i % n});
        if (t[i / n][i % n] == 2) c.push_back({i / n, i % n});
    }

    dfs2(0, m);
    cout << ans;
}