#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> vec;

int sol() {
    int t = 1;

    sort(vec.begin(), vec.end());

    for (const auto &el: vec) {
        if (el.first > t) t = el.first;
        t += el.second;
    }

    return t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    vec.resize(n);
    for (auto &el: vec) {
        cin >> el.first >> el.second;
    }

    cout << sol();

    return 0;
}