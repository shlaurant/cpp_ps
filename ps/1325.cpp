#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> mp[10001];

map<int, vector<int>> d;
bool v[10001];

int go(int i) {
    int ret = 1;
    v[t] = true;

    for (auto c: mp[t]) {
        if (c == t) continue;
        if (!v[c]) ret += go(c);
    }

    return ret;
}

int solve() {
    auto mx = 0;

    for (auto i = 1; i <= n; ++i) {
        fill(v, v + 10001, false);
        int t = go(i);
        d[t].push_back(i);
        mx = max(mx, t);
    }

    sort(d[mx].begin(), d[mx].end());
    return mx;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    int a, b;
    for (auto i = 0; i < m; ++i) {
        cin >> a >> b;
        mp[b].push_back(a);
    }

    for (auto i: d[solve()]) {
        cout << i << ' ';
    }

    return 0;
}