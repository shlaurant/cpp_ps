#include <bits/stdc++.h>

using namespace std;

struct edge {
    int u, v, p;
};

int v, e;
int s, d;

vector<vector<int>> dist;

vector<edge> adj;

int sol() {
    for (auto k = 0; k < v; ++k) {
        for (auto i = 0; i < v; ++i) {
            for (auto j = 0; j < v; ++j) {
                if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    auto sp = dist[s][d];
    int ret = INT_MAX;
    for (const auto &el: adj) {
        if (dist[s][el.u] != INT_MAX) {
            auto cand = dist[s][el.u] + el.p;
            if (cand != sp) ret = min(ret, cand);
        }
    }
    return ret != INT_MAX ? ret : -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (true) {
        cin >> v >> e;
        if (v == 0 && e == 0) break;
        cin >> s >> d;
        dist.resize(v, vector<int>(v, INT_MAX));
        for (auto &rw: dist) {
            fill(rw.begin(), rw.end(), INT_MAX);
        }
        for (auto i = 0; i < v; ++i) dist[i][i] = 0;

        adj.clear();
        for (auto i = 0; i < e; ++i) {
            edge _e;
            cin >> _e.u >> _e.v >> _e.p;
            dist[_e.u][_e.v] = _e.p;
            if (_e.v == d) adj.push_back(_e);
        }

        cout << sol() << '\n';
    }

    return 0;
}