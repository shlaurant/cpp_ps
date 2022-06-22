#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> in;

int sol() {
    vector<int> vec(n);
    sort(in.begin(), in.end());

    int len = 0;
    for (const auto &el: in) {
        auto it = lower_bound(vec.begin(), vec.begin() + len, el.second);
        if (*it == 0) ++len;
        *it = el.second;
    }

    return n - len;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    in.resize(n);
    for (auto &el: in) {
        cin >> el.first >> el.second;
    }

    cout << sol();

    return 0;
}