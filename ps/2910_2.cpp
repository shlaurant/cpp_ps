#include <bits/stdc++.h>

using namespace std;

int n, c;
vector<int> p;

vector<pair<int, int>> ans;

map<int, int> mp;
map<int, int> mp_o;

bool comp(const pair<int, int> &l, const pair<int, int> &r) {
    if (l.second != r.second) {
        return l.second > r.second;
    } else {
        return mp_o[l.first] < mp_o[r.first];
    }
}

void sol() {
    int cnt = 0;
    for (auto el: p) {
        ++mp[el];
        if (mp[el] == 1) {
            mp_o[el] = cnt;
            ++cnt;
        }
    }
    for (const auto &el: mp) {
        ans.emplace_back(el);
    }
    sort(ans.begin(), ans.end(), comp);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> c;
    p.resize(n);
    for (auto &el: p) {
        cin >> el;
    }

    sol();

    for (auto el: ans) {
        for (auto i = 0; i < el.second; ++i) {
            cout << el.first << ' ';
        }
    }

    return 0;
}