#include <bits/stdc++.h>

using namespace std;

int n, l;
vector<pair<int, int>> ponds;

int sol() {
    int ret = 0;

    sort(ponds.begin(), ponds.end());

    int b = 0, e = 0;
    for (const auto &el: ponds) {
        if (el.first >= e) {
            ret += (e - b) / l;
            b = el.first;
        }
        if (el.second > e) {
            e = el.second;
            if ((e - b) % l != 0) e += l - (e - b) % l;
        }
    }

    ret += (e - b) / l;

    return ret;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> l;
    ponds.resize(n);
    for (auto &el: ponds) {
        cin >> el.first >> el.second;
    }

    cout << sol();

    return 0;
}