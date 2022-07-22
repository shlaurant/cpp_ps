#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll sol(ll cnt, ll win) {
    const ll mx = 1e9;
    ll ori = 100ll * win / cnt;
    ll ret = mx;
    ll l = 1, r = mx + 1;
    while (l < r) {
        auto mid = (l + r) / 2;
        if (ori < 100ll * (win + mid) / (cnt + mid)) {
            ret = mid;
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

    ll x, y;
    cin >> x >> y;
    if (100ll * y / x >= 99) {
        cout << -1;
    } else {
        cout << sol(x, y);
    }

    return 0;
}