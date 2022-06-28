#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> mp;

vector<vector<int>> dp;

int lookup(int city, int track) {
    if (dp[city][track] != -1) return dp[city][track];

    int ret = 16 * 1e6 + 1;
    for (auto prev_city = 0; prev_city < n; ++prev_city) {
        if ((track & 1 << prev_city) && mp[prev_city][city] != 0) {
            ret = min(ret, lookup(prev_city, track & ~(1 << prev_city)) +
                           mp[prev_city][city]);
        }
    }
    dp[city][track] = ret;
    return ret;
}

int sol() {
    dp.resize(n, vector<int>(1 << n, -1));
    dp[0][0] = 0;


    return lookup(0, (1 << n) - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    mp.resize(n, vector<int>(n));
    for (auto &rw: mp) {
        for (auto &el: rw) {
            cin >> el;
        }
    }

    cout << sol();

    return 0;
}