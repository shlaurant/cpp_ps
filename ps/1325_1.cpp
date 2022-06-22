#include <bits/stdc++.h>

using namespace std;

vector<int> ans;
vector<vector<int>> mp;

int dfs(vector<vector<int>> &g, int i, vector<bool> &v) {
    int ret = 1;
    v[i] = true;

    for (const auto &child: g[i]) {
        if (v[child]) continue;
        ret += dfs(g, child, v);
    }
    return ret;
}

void sol(vector<vector<int>> &g) {
    vector<bool> v(g.size());
    mp.resize(g.size());

    for (auto i = 0; i < g.size(); ++i) {
        fill(v.begin(), v.end(), false);
        mp[dfs(g, i, v)].push_back(i);
    }

    for(auto i = mp.size() - 1; i >= 0; --i){
        if(!mp[i].empty()){
            sort(mp[i].begin(), mp[i].end());
            copy(mp[i].begin(), mp[i].end(), back_inserter(ans));
            break;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    cin >> n >> m;

    vector<vector<int>> g(n);
    int a, b;
    for (auto i = 0; i < m; ++i) {
        cin >> a >> b;
        g[b - 1].push_back(a - 1);
    }

    sol(g);

    for (auto i: ans) {
        cout << i + 1 << ' ';
    }
}