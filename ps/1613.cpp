#include <bits/stdc++.h>

using namespace std;

const int mx = INT_MAX;

int n, k, s;
vector<vector<int>> dist;

void fw();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    dist.resize(n, vector<int>(n, mx));
    for (auto i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }

    for (auto i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        dist[--a][--b] = 1;
    }

    fw();

    cin >> s;
    for (auto i = 0; i < s; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        if (dist[a][b] != mx) cout << -1 << '\n';
        else if (dist[b][a] != mx) cout << 1 << '\n';
        else cout << 0 << '\n';
    }

    return 0;
}

void fw() {
    for (auto k = 0; k < n; ++k) {
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < n; ++j) {
                if (dist[i][k] == mx || dist[k][j] == mx) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}