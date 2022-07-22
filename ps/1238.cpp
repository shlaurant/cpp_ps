#include <bits/stdc++.h>

using namespace std;

int n, m, x;
vector<vector<pair<int, int>>> adj;

vector<int> dist_back;

void dijk(int s, vector<int> &dist) {
    dist.resize(n);
    fill(dist.begin(), dist.end(), INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        if (p.first > dist[p.second]) continue;
        for (const auto &el: adj[p.second]) {
            if (dist[el.first] > p.first + el.second) {
                dist[el.first] = p.first + el.second;
                pq.push({dist[el.first], el.first});
            }
        }
    }
}

int sol() {
    int mx = INT_MIN;

    dijk(x, dist_back);
    vector<int> dist;

    for (auto i = 0; i < n; ++i) {
        dijk(i, dist);
        mx = max(mx, dist[x] + dist_back[i]);
    }

    return mx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> x;
    --x;
    adj.resize(n);
    for (auto i = 0; i < m; ++i) {
        int u, v, d;
        cin >> u >> v >> d;
        adj[--u].push_back({--v, d});
    }

    cout << sol();

    return 0;
}