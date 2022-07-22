#include <bits/stdc++.h>

using namespace std;

int n, m, x;

vector<vector<int>> adj;
vector<vector<int>> r_adj;

vector<bool> rv;
vector<bool> lv;

int mn;
int mx;

void bfs(int s, const vector<vector<int>> &av, vector<bool> &visit) {
    queue<int> q;
    visit[s] = true;
    q.push(s);
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        for (auto el: av[p]) {
            if (!visit[el]) {
                visit[el] = true;
                q.push(el);
            }
        }
    }
}

int cnt(const vector<bool> &v) {
    int ret = 0;

    for (auto el: v) {
        if (el) ++ret;
    }

    return ret;
}

void sol() {
    rv.resize(n + 1);
    lv.resize(n + 1);

    bfs(x, adj, rv);
    bfs(x, r_adj, lv);

    mn = cnt(lv);
    mx = n - cnt(rv) + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> x;
    adj.resize(n + 1);
    r_adj.resize(n + 1);
    for (auto i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        r_adj[b].push_back(a);
    }

    sol();

    cout << mn << ' ' << mx;

    return 0;
}