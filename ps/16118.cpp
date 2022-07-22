#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
vector<vector<pair<int, int>>> adj;

vector<bool> stp_fox;
vector<vector<bool>> stp_wolf;
vector<ll> dist_fox;
vector<vector<ll>> dist_wolf;

int find_min(const vector<ll> &dist, const vector<bool> &stp) {
    ll mn = LONG_LONG_MAX;
    int ret = -1;

    for (auto i = 0; i < n; ++i) {
        if (dist[i] < mn && !stp[i]) {
            mn = dist[i];
            ret = i;
        }
    }

    return ret;
}

void dijk_fox() {
    stp_fox.resize(n);
    dist_fox.resize(n, LONG_LONG_MAX);
    dist_fox[0] = 0;
    while (true) {
        auto p = find_min(dist_fox, stp_fox);
        if (p == -1) break;
        stp_fox[p] = true;
        for (const auto &el: adj[p]) {
            if (stp_fox[el.first]) continue;
            dist_fox[el.first] = min(dist_fox[el.first],
                                     dist_fox[p] + el.second);
        }
    }
}

void update(int p, int from) {
    int to = (from + 1) % 2;
    for (const auto &el: adj[p]) {
        if (stp_wolf[to][el.first]) continue;
        ll dist = from == 0 ? el.second / 2 : el.second * 2;
        dist_wolf[to][el.first] = min(dist_wolf[to][el.first],
                                      dist_wolf[from][p] + dist);
    }
}

void dijk_wolf() {
    stp_wolf.resize(2, vector<bool>(n));
    dist_wolf.resize(2, vector<ll>(n, LONG_LONG_MAX));
    dist_wolf[0][0] = 0;
    while (true) {
        auto p0 = find_min(dist_wolf[0], stp_wolf[0]);
        auto p1 = find_min(dist_wolf[1], stp_wolf[1]);
        if (p0 != -1 && p1 != -1) {
            if (dist_wolf[0][p0] > dist_wolf[1][p1]) {
                stp_wolf[1][p1] = true;
                update(p1, 1);
            } else {
                stp_wolf[0][p0] = true;
                update(p0, 0);
            }
        } else if (p0 == -1 && p1 == -1) {
            break;
        } else {
            if(p0 != -1){
                stp_wolf[0][p0] = true;
                update(p0, 0);
            } else{
                stp_wolf[1][p1] = true;
                update(p1, 1);
            }
        }
    }
}

int sol() {
    int ret = 0;
    dijk_fox();
    dijk_wolf();
    for (auto i = 0; i < n; ++i) {
        if (dist_fox[i] < dist_wolf[0][i] && dist_fox[i] < dist_wolf[1][i])
            ++ret;
    }
    return ret;
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
        --a;
        --b;
        c *= 2;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    cout << sol();

    return 0;
}