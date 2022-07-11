#include <bits/stdc++.h>

using namespace std;

struct quest {
    int s, i, p;
};

int n;
vector<quest> qv;

vector<vector<int>> dp;
vector<bool> visit;

int look_up(int str, int intel) {
    if (dp[str][intel] != -1) return dp[str][intel];

    int val = 0;
    int pnt = 0;
    vector<int> rev;
    for (auto i = 0; i < n; ++i) {
        if (qv[i].s <= str || qv[i].i <= intel) {
            ++val;
            if (!visit[i]) {
                visit[i] = true;
                rev.push_back(i);
                pnt += qv[i].p;
            }
        }
    }

    if (pnt > 0) {
        for (auto i = 0; i <= pnt; ++i) {
            val = max(val,
                      look_up(min(1000, str + i), min(1000, intel + pnt - i)));
        }
    }

    for (auto el: rev) {
        visit[el] = false;
    }

    dp[str][intel] = val;
    return dp[str][intel];
}

int sol() {
    dp.resize(1001, vector<int>(1001, -1));
    visit.resize(n);

    return look_up(1, 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    qv.resize(n);
    for (auto &el: qv) {
        cin >> el.s >> el.i >> el.p;
    }

    cout << sol();

    return 0;
}