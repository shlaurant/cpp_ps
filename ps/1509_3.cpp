#include <bits/stdc++.h>

using namespace std;

const int mx = 2501;

string str;

vector<vector<bool>> pv;
vector<int> dp;

void make_pv() {
    pv.resize(str.size(), vector<bool>(str.size() + 1));
    for (auto sz = 1; sz <= str.size(); ++sz) {
        for (auto i = 0; i + sz <= str.size(); ++i) {
            if (sz == 1) pv[i][i + 1] = true;
            else if (sz == 2) {
                if (str[i] == str[i + 1]) pv[i][i + 2] = true;
            } else {
                pv[i][i + sz] =
                        str[i] == str[i + sz - 1] && pv[i + 1][i + sz - 1];
            }
        }
    }
}

int look_up(int index) {
    if (index == str.size()) return 0;
    if (dp[index] != -1) return dp[index];

    int val = mx;

    for (auto sz = 1; index + sz <= str.size(); ++sz) {
        if (pv[index][index + sz]) val = min(val, look_up(index + sz) + 1);
    }

    dp[index] = val;
    return dp[index];
}

int sol() {
    make_pv();
    dp.resize(str.size(), -1);
    return look_up(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> str;

    cout << sol();

    return 0;
}