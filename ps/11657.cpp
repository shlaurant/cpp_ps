#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct edge {
    int u, v, w;
};

int n, m;
vector<edge> ev;

vector<ll> dist;

void iterate() {
    for (const auto &el: ev) {
        if (dist[el.u] != LONG_LONG_MAX) {
            if (dist[el.v] > dist[el.u] + el.w) {
                dist[el.v] = dist[el.u] + el.w;
            }
        }
    }
}

void check(){
    for (const auto &el: ev) {
        if (dist[el.u] != LONG_LONG_MAX) {
            if (dist[el.v] > dist[el.u] + el.w) {
                cout << -1;
                exit(0);
            }
        }
    }
}

void sol() {
    dist.resize(n + 1, LONG_LONG_MAX);
    dist[1] = 0;

    for (auto i = 0; i < n - 1; ++i) {
        iterate();
    }

    check();
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    ev.resize(m);
    for (auto &el: ev) {
        cin >> el.u >> el.v >> el.w;
    }

    sol();
    for (auto i = 2; i <= n; ++i) {
        dist[i] != LONG_LONG_MAX ? cout << dist[i] << '\n' : cout << -1 << '\n';
    }

    return 0;
}