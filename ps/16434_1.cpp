#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct room {
    ll t, a, h;
};

int n, atk;
vector<room> dungeon;

void clear_room(const room &r, ll &ca, ll &chp, ll mhp) {
    if (r.t == 1) {
        auto cnt = r.h / ca;
        if(r.h % ca ) ++cnt;
        auto _cnt = chp / r.a;
        if(chp % r.a) ++_cnt;
        if (cnt > _cnt) {
            chp = -1;
        } else {
            chp -= r.a * (cnt - 1);
        }
    } else {
        ca += r.a;
        chp = min(mhp, chp + r.h);
    }
    return;
}

bool can_clear(ll mxhp) {
    auto chp = mxhp;
    ll ca = atk;
    for (const auto &el: dungeon) {
        clear_room(el, ca, chp, mxhp);
        if (chp <= 0) return false;
    }
    return true;
}

ll sol() {
    ll mnhp = LONG_LONG_MAX;
    ll l = 1;
    ll r = 1e18;
    while (l < r) {
        auto mid = (l + r) / 2;
        if (can_clear(mid)) {
            mnhp = min(mid, mnhp);
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return mnhp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> atk;
    dungeon.resize(n);
    for (auto &el: dungeon) {
        cin >> el.t >> el.a >> el.h;
    }

    cout << sol();

    return 0;
}