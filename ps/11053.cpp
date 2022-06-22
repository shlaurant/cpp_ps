#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;

int sol() {
    int ret = 0;

    vector<int> cnt(n);

    for (auto i = 0; i < n; ++i) {
        int mx = 0;
        for (auto j = 0; j < i; ++j) {
            if (a[i] > a[j]) mx = max(mx, cnt[j]);
        }
        cnt[i] = mx + 1;
        ret = max(ret, cnt[i]);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    a.resize(n);
    for (auto &el: a) {
        cin >> el;
    }

    cout << sol();

    return 0;
}