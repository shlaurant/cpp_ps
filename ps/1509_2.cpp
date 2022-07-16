#include <bits/stdc++.h>

using namespace std;

const int mx = 2501;

string str;
vector<vector<bool>> is_pal;
vector<int> dp;

void make_pal() {
    is_pal.resize(str.size(), vector<bool>(str.size() + 1));

    for (auto sz = 1; sz <= str.size(); ++sz) {
        for (auto i = 0; i + sz <= str.size(); ++i) {
            if (sz == 1) is_pal[i][i + 1] = true;
            else if (sz == 2) is_pal[i][i + 2] = str[i] == str[i + 1];
            else {
                is_pal[i][i + sz] =
                        is_pal[i + 1][i + sz - 1] && str[i] == str[i + sz - 1];
            }
        }
    }
}

int look_up(int index) {
    if (index >= str.size()) return 0;
    if (dp[index] != mx) return dp[index];

    int val = INT_MAX;

    for (auto sz = 1; sz + index <= str.size(); ++sz) {
        if (is_pal[index][index + sz])
            val = min(val, look_up(index + sz) + 1);
    }

    dp[index] = val;
    return dp[index];
}

int sol() {
    make_pal();
    dp.resize(str.size(), mx);
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