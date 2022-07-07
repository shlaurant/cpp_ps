#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> lines;

int sol() {
    int ret = 0;

    sort(lines.begin(), lines.end());
    int l = lines.front().first;
    int r = lines.front().second;
    for (auto i = 1; i < n; ++i) {
        if (lines[i].first <= r) {
            r = max(r, lines[i].second);
        } else {
            ret += r - l;
            l = lines[i].first;
            r = lines[i].second;
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
    lines.resize(n);
    for (auto &el: lines) {
        cin >> el.first >> el.second;
    }

    cout << sol();

    return 0;
}