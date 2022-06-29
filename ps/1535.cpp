#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> hp_ple;

int sol() {
    int ret = 0;

    for (auto i = 0; i < 1 << n; ++i) {
        auto cur_hp = 100;
        auto cur_ple = 0;
        for (auto j = 0; j < n; ++j) {
            if (i & 1 << j) {
                cur_hp -= hp_ple[j].first;
                cur_ple += hp_ple[j].second;
                if (cur_hp <= 0) break;
            }
        }
        if (cur_hp > 0) {
            ret = max(ret, cur_ple);
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    hp_ple.resize(n);
    for (auto &el: hp_ple) {
        cin >> el.first;
    }
    for (auto &el: hp_ple) {
        cin >> el.second;
    }

    cout << sol();

    return 0;
}