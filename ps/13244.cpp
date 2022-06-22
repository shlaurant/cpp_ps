#include <bits/stdc++.h>

using namespace std;

int t;

vector<vector<int>> graph;
vector<bool> v;

bool bfs() {
    queue<int> q;
    v[0] = true;
    q.push(0);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto np: graph[cur]) {
            if (np == -1) continue;
            if (v[np]) return false;
            q.push(np);
            v[np] = true;
            auto it = find(graph[np].begin(), graph[np].end(), cur);
            *it = -1;
        }
    }

    return find(v.begin(), v.end(), false) == v.end();
}

void sol(int n, int m) {
    graph.clear();
    graph.resize(n, vector<int>());
    v.clear();
    v.resize(n, false);

    int a, b;
    for (auto i = 0; i < m; ++i) {
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    bfs() ? cout << "tree" : cout << "graph";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    int n, m;
    for (auto i = 0; i < t; ++i) {
        cin >> n >> m;
        sol(n, m);
        cout << '\n';
    }


    return 0;
}