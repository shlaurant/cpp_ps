#include <bits/stdc++.h>

using namespace std;

vector<char> seq;

vector<int> dp0;
vector<vector<int>> dp1;

int look_up0(int e) {
    if (dp0[e] != -1) return dp0[e];

    if (dp1[0][e] == 1) {
        dp0[e] = 1;
    } else {
        int val = INT_MAX;
        for (auto i = 1; i < e; ++i) {
            if (dp1[i][e] == 1) {
                val = min(val, look_up0(i) + 1);
            }
        }
        dp0[e] = val;
    }

    return dp0[e];
}

void _tab1(int sz) {
    for (auto i = 0; i + sz <= seq.size(); ++i) {
        if (seq[i] != seq[i + sz - 1]) {
            dp1[i][i + sz] = 0;
        } else if (sz <= 2) {
            dp1[i][i + sz] = 1;
        } else {
            dp1[i][i + sz] = dp1[i + 1][i + sz - 1];
        }
    }
}

void tab1() {
    for (auto sz = 1; sz <= seq.size(); ++sz) {
        _tab1(sz);
    }
}

int sol() {
    dp0.resize(seq.size() + 1, -1);
    dp1.resize(seq.size(), vector<int>(seq.size() + 1, -1));

    tab1();

    return look_up0(seq.size());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    char c;
    while (cin >> c) {
#ifndef ONLINE_JUDGE
        if (!isalpha(c)) break;
#endif
        seq.push_back(c);
    }

    cout << sol();

    return 0;
}