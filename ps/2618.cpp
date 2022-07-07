#include <bits/stdc++.h>

using namespace std;

int n, w;
vector<pair<int, int>> wv;

int dist = 0;
vector<int> ans;

vector<vector<int>> dp;

int db(const pair<int, int> &a, const pair<int, int> &b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int look_up(int a, int b) {
    if (a == w || b == w) return 0;
    if (dp[a][b] != -1) return dp[a][b];
    auto next = max(a, b) + 1;
    auto posb = b != 0 ? wv[b] : pair<int, int>{n, n};
    dp[a][b] = min(look_up(next, b) + db(wv[a], wv[next]),
                   look_up(a, next) + db(posb, wv[next]));
    return dp[a][b];
}

void trace() {
    auto a = 0, b = 0;
    for (auto i = 0; i < w; ++i) {
        auto next = max(a, b) + 1;
        auto posb = b != 0 ? wv[b] : pair<int, int>{n, n};
        if (look_up(next,b) + db(wv[a], wv[next]) < look_up(a, next)+ db(posb, wv[next])) {
            ans.push_back(1);
            a = next;
        } else {
            ans.push_back(2);
            b = next;
        }
    }
}

void sol() {
    dp.resize(w, vector<int>(w, -1));
    dist = look_up(0, 0);
    trace();
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> w;
    wv.resize(w);
    for (auto &el: wv) {
        cin >> el.first >> el.second;
    }
    wv.insert(wv.begin(), {1, 1});

    sol();
    cout << dist << '\n';
    for (auto el: ans) {
        cout << el << '\n';
    }

    return 0;
}