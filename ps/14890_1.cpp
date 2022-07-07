#include <bits/stdc++.h>

using namespace std;

int n, l;
vector<vector<int>> mp;

bool is_road(const vector<int> &v) {
    vector<pair<int, int>> h;
    for (auto i = 0; i < v.size() - 1; ++i) {
        if (v[i] != v[i + 1]) h.push_back({i, i + 1});
    }

    vector<bool> visit(v.size());
    for (const auto &el: h) {
        if (abs(v[el.first] - v[el.second]) > 1) return false;
        if (v[el.first] > v[el.second]) {
            if (el.first + l >= v.size()) return false;
            auto curh = v[el.second];
            for (auto i = el.second; i < el.second + l; ++i) {
                if (curh != v[i]) return false;
                if (visit[i]) return false;
                visit[i] = true;
            }
        } else {
            if (el.second - l < 0) return false;
            auto curh = v[el.first];
            for (auto i = el.first; i > el.first - l; --i) {
                if (curh != v[i]) return false;
                if (visit[i]) return false;
                visit[i] = true;
            }
        }
    }
    return true;
}

int sol() {
    int ret = 0;

    for (const auto &rw: mp) {
        if (is_road(rw)) ++ret;
    }
    for (auto i = 0; i < n; ++i) {
        vector<int> v;
        for (const auto &rw: mp) {
            v.push_back(rw[i]);
        }
        if (is_road(v)) ++ret;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> l;
    mp.resize(n, vector<int>(n));
    for (auto &rw: mp) {
        for (auto &el: rw) {
            cin >> el;
        }
    }

    cout << sol();

    return 0;
}