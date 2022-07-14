#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> seq;
vector<int> op(4);

int mx = INT_MIN;
int mn = INT_MAX;

void rec(int val, int index) {
    if (index == n) {
        mx = max(mx, val);
        mn = min(mn, val);
        return;
    }

    for (auto i = 0; i < 4; ++i) {
        if (op[i] == 0) continue;
        --op[i];
        switch (i) {
            case 0:
                rec(val + seq[index], index + 1);
                break;
            case 1:
                rec(val - seq[index], index + 1);
                break;
            case 2:
                rec(val * seq[index], index + 1);
                break;
            case 3:
                rec(val / seq[index], index + 1);
                break;
        }
        ++op[i];
    }
}

void sol() {
    rec(seq[0], 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    seq.resize(n);
    for (auto &el: seq) {
        cin >> el;
    }
    for (auto &el: op) {
        cin >> el;
    }

    sol();

    cout << mx << '\n' << mn;

    return 0;
}