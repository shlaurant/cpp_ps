#include <bits/stdc++.h>

using namespace std;

int n;

int cnt;
vector<int> trace;

vector<int> dp;

int look_up(int i) {
    if (dp[i] != -1) return dp[i];
    if (i == 1) return 0;

    int val = INT_MAX;

    if (i % 3 == 0) {
        val = min(val, look_up(i / 3) + 1);
    }

    if (i % 2 == 0) {
        val = min(val, look_up(i / 2) + 1);
    }

    val = min(val, look_up(i - 1) + 1);

    dp[i] = val;
    return dp[i];
}

void make_trace() {
    auto i = n;
    while (i != 1) {
        trace.push_back(i);
        int next = i - 1;
        int val = look_up(next);
        if (i % 3 == 0 && look_up(i / 3) < val) {
            next = i / 3;
            val = look_up(next);
        }
        if (i % 2 == 0 && look_up(i / 2) < val) {
            next = i / 2;
            val = look_up(next);
        }
        i = next;
    }
    trace.push_back(i);
}

void sol() {
    dp.resize(n + 1, -1);
    cnt = look_up(n);

    make_trace();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    sol();

    cout << cnt << '\n';
    for (auto el: trace) {
        cout << el << ' ';
    }

    return 0;
}