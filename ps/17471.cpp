#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> pop;
vector<vector<int>> adj;
vector<bool> team;
vector<bool> v;

void mark_team(int i) {
    for (auto j = 0; j < n; ++j) {
        i & 1 << j ? team[j] = true : team[j] = false;
    }
}

void dfs(int p, bool t) {
    v[p] = true;
    for (auto np: adj[p]) {
        if (!v[np] && team[np] == t) dfs(np, t);
    }
}

void start_dfs(bool t) {
    int s = -1;
    for (auto i = 0; i < n; ++i) {
        if (team[i] == t) {
            s = i;
            break;
        }
    }

    dfs(s, t);
}

int pop_diff() {
    int tt = 0;
    int tf = 0;

    for (auto i = 0; i < n; ++i) {
        if (team[i]) tt += pop[i];
        else tf += pop[i];
    }

    return abs(tt - tf);
}

int sol() {
    int ret = INT_MAX;
    team.resize(n);
    v.resize(n);

    for (auto i = 1; i < (1 << n) - 1; ++i) {
        mark_team(i);
        fill(v.begin(), v.end(), false);
        start_dfs(false);
        start_dfs(true);
        if (find(v.begin(), v.end(), false) != v.end()) continue;
        ret = min(ret, pop_diff());
    }

    return ret == INT_MAX ? -1 : ret;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    pop.resize(n);
    for (auto &el: pop) {
        cin >> el;
    }

    adj.resize(n);
    for (auto &rw: adj) {
        int t, k;
        cin >> t;
        for (auto i = 0; i < t; ++i) {
            cin >> k;
            rw.push_back(k - 1);
        }
    }

    cout << sol();
    return 0;
}