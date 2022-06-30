#include <bits/stdc++.h>

using namespace std;

vector<int> seq;

vector<vector<vector<int>>> dp;

int energy(int s, int e) {
    if (s == e) return 1;
    if (s == 0) {
        return 2;
    } else if (abs(e - s) == 2) {
        return 4;
    } else {
        return 3;
    }
}

int look_up(int index, int l, int r) {
    if (index >= seq.size()) return 0;
    if (dp[index][l][r]) return dp[index][l][r];

    int val = INT_MAX;
    if (seq[index] != r)
        val = min(val, look_up(index + 1, seq[index], r) +
                       energy(l, seq[index]));
    if (seq[index] != l)
        val = min(val, look_up(index + 1, l, seq[index]) +
                       energy(r, seq[index]));
    dp[index][l][r] = val;
    return val;
}

int sol() {
    dp.resize(seq.size(), vector<vector<int>>(5, vector<int>(5)));
    return look_up(0, 0, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int i;
    while (cin >> i) {
        if (i == 0) break;
        seq.push_back(i);
    }

    cout << sol();

    return 0;
}