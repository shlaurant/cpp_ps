#include <bits/stdc++.h>

using namespace std;

int n, c;
vector<int> seq;

vector<int> vl, vr;

int sol() {
    for (auto i = 0; i < 1 << n / 2; ++i) {
        int sum = 0;
        for (auto j = 0; j < n / 2; ++j) {
            if (i & 1 << j) sum += seq[j];
            if (sum > c) break;
        }
        if (sum <= c) vl.push_back(sum);
    }

    for (auto i = 0; i < 1 << (n + 1) / 2; ++i) {
        int sum = 0;
        for (auto j = 0; j < (n + 1) / 2; ++j) {
            if (i & 1 << j) sum += seq[j + n / 2];
            if (sum > c) break;
        }
        if (sum <= c) vr.push_back(sum);
    }

    sort(vl.begin(), vl.end());
    sort(vr.begin(), vr.end());

    int ret = 0;

    for (auto el: vl) {
        auto it = upper_bound(vr.begin(), vr.end(), (c - el));
        ret += (it - vr.begin());
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> c;
    seq.resize(n);
    for (auto &el: seq) {
        cin >> el;
    }

    cout << sol();

    return 0;
}