#include <bits/stdc++.h>

using namespace std;

bool can_plug(int i, const vector<int> &pg) {
    return any_of(pg.begin(), pg.end(),
                  [i](int el) -> bool { return el == i || el == 0; });
}


void do_plug(int i, vector<int> &pg) {
    if (any_of(pg.begin(), pg.end(), [i](int el) -> bool { return el == i; })) {
        return;
    }
    for (auto &el: pg) {
        if (el == 0) {
            el = i;
            return;
        }
    }
}

void unplug(int b, vector<int> &pg, const vector<int> &per) {
    if (b >= per.size()) {
        pg.front() = 0;
        return;
    }

    int mx = 0, mx_i;
    for (auto i = 0; i < pg.size(); ++i) {
        auto it = find(per.begin() + b, per.end(), pg[i]);
        if (it == per.end()) {
            pg[i] = 0;
            return;
        } else {
            if (mx < it - per.begin()) {
                mx = it - per.begin();
                mx_i = i;
            }
        }
    }
    pg[mx_i] = 0;
}

int sol(int n, int k, const vector<int> &vp) {
    int ret = 0;

    vector<int> plug(n);
    for (auto i = 0; i < k; ++i) {
        if (can_plug(vp[i], plug)) {
            do_plug(vp[i], plug);
        } else {
            unplug(i + 1, plug, vp);
            ++ret;
            do_plug(vp[i], plug);
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    auto vp = new vector<int>(k);
    for (auto &el: *vp) {
        cin >> el;
    }

    cout << sol(n, k, *vp);

    delete vp;

    return 0;
}