#include <bits/stdc++.h>

using namespace std;

int v, e;
int start;
vector<vector<pair<int, int>>> edges;

vector<int> dist;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

int sol() {
    dist.resize(v + 1, INT_MAX);

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if (cur.first > dist[cur.second]) continue;
        for (const auto &el: edges[cur.second]) {
            if (dist[el.first] > cur.first + el.second) {
                dist[el.first] = cur.first + el.second;
                pq.push({dist[el.first], el.first});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> v >> e >> start;
    edges.resize(v + 1);

    for (auto i = 0; i < e; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
    }

    sol();

    for (auto i = 1; i <= v; ++i) {
        dist[i] == INT_MAX ?
        cout << "INF" << '\n' :
        cout << dist[i] << '\n';
    }

    return 0;
}