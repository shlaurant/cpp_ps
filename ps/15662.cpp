#include <bits/stdc++.h>

using namespace std;

int t;
vector<int> gears;
int k;
vector<pair<int, int>> rot;

void _rot(int index, int dir, vector<bool> &v) {
    bool l = false, r = false;
    if (index - 1 >= 0) {
        l = (bool)(gears[index] & 1 << 6) != (bool)(gears[index - 1] & 1 << 2);
    }
    if (index + 1 < t) {
        r = (bool)(gears[index] & 1 << 2) != (bool)(gears[index + 1] & 1 << 6);
    }
    v[index] = true;
    if (dir == 1) {
        int i = gears[index] >> 7;
        gears[index] = (gears[index] << 1) + i;
        gears[index] &= ~(1 << 8);
    } else {
        int i = gears[index] & 1;
        gears[index] = gears[index] >> 1;
        gears[index] += i << 7;
    }
    if (l && !v[index - 1]) _rot(index - 1, -dir, v);
    if (r && !v[index + 1]) _rot(index + 1, -dir, v);
}

void mrotate(const pair<int, int> &r) {
    vector<bool> visit(t);
    _rot(r.first, r.second, visit);
}

int cnts() {
    int ret = 0;

    for (auto el: gears) {
        if (el & 1) ++ret;
    }

    return ret;
}

int sol() {

    for (const auto &el: rot) {
        mrotate(el);
    }
    return cnts();
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    gears.resize(t);
    for (auto &g: gears) {
        int i = 0;
        char c;
        for (auto j = 0; j < 8; ++j) {
            cin >> c;
            i += (c - '0') << j;
        }
        g = i;
    }

    cin >> k;
    rot.resize(k);
    for (auto &el: rot) {
        cin >> el.first >> el.second;
        --el.first;
    }

    cout << sol();

    return 0;
}