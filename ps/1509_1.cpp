//1530
#include <bits/stdc++.h>

using namespace std;

string str;

vector<int> dp;
vector<vector<bool>> pv;

void make_pv() {
    for (auto sz = 1; sz <= str.size(); ++sz) {
        for (auto i = 0; i < str.size(); ++i) {
            if (i + sz > str.size()) continue;
            if (sz == 1) {
                pv[i][i + 1] = true;
            } else if (sz == 2) {
                pv[i][i + 2] = str[i] == str[i + 1];
            } else {
                pv[i][i + sz] =
                        pv[i + 1][i + sz - 1] && str[i] == str[i + sz - 1];
            }
        }
    }
}

int look_up(int index) {
    if (dp[index]) return dp[index];
    if (index == 0) return 0;

    int val = INT_MAX;

    for (auto sz = 1; sz <= index; ++sz) {
        if (pv[index - sz][index])
            val = min(val, look_up(index - sz) + 1);
    }

    dp[index] = val;
    return dp[index];
}

int sol() {
    dp.resize(str.size()+1);
    pv.resize(str.size(), vector<bool>(str.size() + 1));

    make_pv();

    return look_up(str.size());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> str;

    cout << sol();

    return 0;
}