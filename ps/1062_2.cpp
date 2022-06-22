#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<vector<int>> adj;

vector<int> ans;
vector<bool> v;

int dfs(int s) {
    v[s] = true;
    int ret = 1;

    for (auto el: adj[s]) {
        if (!v[el]) {
            ret += dfs(el);
        }
    }

    return ret;
}

void sol() {
    int mx = 0;
    v.resize(n);
    for (auto i = 0; i < n; ++i) {
        fill(v.begin(), v.end(), false);
        auto t = dfs(i);
        if (t > mx) {
            ans.clear();
            ans.push_back(i);
            mx = t;
        } else if (t == mx) {
            ans.push_back(i);
        }
    }

    sort(v.begin(), v.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    adj.resize(n);

    for (auto i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[b - 1].push_back(a - 1);
    }

    sol();

    for (auto el: ans) {
        cout << el + 1 << ' ';
    }

    return 0;
}