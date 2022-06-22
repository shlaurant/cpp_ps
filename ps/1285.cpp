#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<char>> coins;

char rev(char c) {
    if (c == 'T') return 'H';
    if (c == 'H') return 'T';
    throw domain_error("??");
}

void turn_row(int row) {
    for (auto i = 0; i < n; ++i) {
        if (row & 1 << i) {
            for (auto &el: coins[i]) {
                el = rev(el);
            }
        }
    }
}

int count_tail(int col) {
    int ret = 0;
    for (const auto &rw: coins) {
        if (rw[col] == 'T') ++ret;
    }
    return ret;
}

int sol() {
    int ret = INT_MAX;

    for (auto r = 0; r < 1 << n; ++r) {
        turn_row(r);
        int temp = 0;
        for (auto col = 0; col < n; ++col) {
            int t = count_tail(col);
            temp += min(t, n - t);
        }
        turn_row(r);
        ret = min(ret, temp);
    }

    return ret;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    coins.resize(n, vector<char>(n));
    for (auto &rw: coins) {
        for (auto &el: rw) {
            cin >> el;
        }
    }

    cout << sol();

    return 0;
}