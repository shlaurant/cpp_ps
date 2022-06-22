#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> v;

int sol() {
    int ret = 0;
    sort(v.begin(), v.end());
    int l, r;
    l = v[0].first;
    r = v[0].second;
    for (auto i = 1; i < n; ++i) {
        if (v[i].first > r) {
            ret += r - l;
            l = v[i].first;
            r = v[i].second;
        } else if(v[i].second > r) {
            r = v[i].second;
        }
    }

    ret += r - l;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    v.resize(n);
    for (auto &el: v) {
        cin >> el.first >> el.second;
    }

    cout << sol();

    return 0;
}