#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<pair<int, int>>> adj;

vector<vector<int>> dist;

void sol() {
    dist.resize(n, vector<int>(n, INT_MAX));
    for (auto b = 0; b < n; ++b) {
        for (const auto &el: adj[b]) {
            dist[b][el.first] = min(dist[b][el.first], el.second);
        }
    }
    for (auto i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }

    for (auto k = 0; k < n; ++k) {
        for (auto b = 0; b < n; ++b) {
            for (auto e = 0; e < n; ++e) {
                if (dist[b][k] != INT_MAX && dist[k][e] != INT_MAX &&
                    dist[b][e] > dist[b][k] + dist[k][e]) {
                    dist[b][e] = dist[b][k] + dist[k][e];
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    adj.resize(n);
    for (auto i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a - 1].push_back({b - 1, c});
    }

    sol();

    for (const auto &rw: dist) {
        for (auto el: rw) {
            el != INT_MAX ? cout << el << ' ' : cout << 0 << ' ';
        }
        cout << '\n';
    }

    return 0;
}