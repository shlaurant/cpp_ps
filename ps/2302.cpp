#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> fix;

vector<int> dp;

int look_up(int cnt) {
    if (cnt == 0) return 1;
    if (cnt == 1) return 1;
    if (cnt == 2) return 2;
    if (dp[cnt] != 0) return dp[cnt];

    int val = 0;
    val += look_up(cnt - 1);
    val += look_up(cnt - 2);
    dp[cnt] = val;
    return dp[cnt];
}

int sol() {
    dp.resize(n + 1);
    int ret = 1;

    int l = 0;
    for (auto el: fix) {
        ret *= look_up(el - l);
        l = el + 1;
    }
    ret *= look_up(n - l);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    fix.resize(m);
    for (auto &el: fix) {
        cin >> el;
        --el;
    }

    cout << sol();

    return 0;
}