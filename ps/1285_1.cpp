#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> coins;

void turn_row(int row) {
    for (auto i = 0; i < n; ++i) {
        if (row & 1 << i) coins[i] = ~coins[i];
    }
}

int count_tail(int col) {
    int ret = 0;
    for (const auto &rw: coins) {
        if (rw & 1 << col) ++ret;
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
    coins.resize(n);
    char c;
    for (auto &el: coins) {
        int ret = 0;
        for (auto i = 0; i < n; ++i) {
            ret <<= 1;
            cin >> c;
            if (c == 'T') ++ret;
        }
        el = ret;
    }
    cout << sol();

    return 0;
}