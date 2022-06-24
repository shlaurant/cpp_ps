#include <bits/stdc++.h>

using namespace std;

struct room {
    int t;
    long long a, h;
};

int n, atk;
vector<room> rooms;

bool can_clear(long long max_hp) {
    long long cur_hp = max_hp;
    long long cur_atk = atk;
    for (auto el: rooms) {
        if (el.t == 1) {
            auto t = el.h / cur_atk;
            if (el.h % cur_atk != 0) ++t;
            cur_hp -= (t - 1) * el.a;
            if (cur_hp <= 0) return false;
        } else {
            cur_hp = min(max_hp, cur_hp + el.h);
            cur_atk += el.a;
        }
    }
    return true;
}

long long sol() {
    long long ret = LONG_LONG_MAX;
    long long l = 1, r = 1000000ll * 1000000ll * 123456ll + 1;

    while (l < r) {
        auto mid = (l + r) / 2;
        if (can_clear(mid)) {
            ret = min(ret, mid);
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> atk;
    rooms.resize(n);
    for (auto &el: rooms) {
        cin >> el.t >> el.a >> el.h;
    }

    cout << sol();

    return 0;
}