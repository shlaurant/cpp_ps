#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<pair<int, int>> cp;

vector<int> dp;

int mstoi(const string &str) {
    auto s = str.substr(0, str.size() - 3);
    s.append(str.substr(str.size() - 2, str.size()));
    return stoi(s);
}

int look_up(int cost) {
    if (dp[cost] != -1) return dp[cost];

    int val = 0;
    for (auto i = 0; i < n; ++i) {
        if (cost - cp[i].second >= 0)
            val = max(val,
                      look_up(cost - cp[i].second) +
                      cp[i].first);

    }
    dp[cost] = val;
    return dp[cost];
}

int sol() {
    dp.resize(m + 1);
    fill(dp.begin(), dp.end(), -1);
    return look_up(m);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (true) {
        string str;
        cin >> n >> str;
        m = mstoi(str);
        if (n == 0 && m == 0) break;
        cp.resize(n);
        for (auto &el: cp) {
            cin >> el.first >> str;
            el.second = mstoi(str);
        }
        cout << sol() << '\n';
    }


    return 0;
}