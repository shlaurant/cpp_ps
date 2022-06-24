#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> ot;

bool check(long long t) {
    long long cnt = 0;
    for (auto el: ot) {
        cnt += t / el;
        if (t % el) ++cnt;
    }
    return cnt >= n;
}

int find_i(long long t) {
    int ret = 0;
    int cnt_l = n;
    for (auto el: ot) {
        cnt_l -= (t - 1) / el;
        if ((t - 1) % el) --cnt_l;
    }

    while (cnt_l > 0) {
        while (!(ot[ret] == 1 || t % ot[ret] == 1)) ++ret;
        --cnt_l;
        ++ret;
    }
    return ret;
}

int sol() {
    long long l = 1, r = 6e10 + 1;
    long long mn = LONG_LONG_MAX;

    while (l < r) {
        long long mid = (l + r) / 2;
        if (check(mid)) {
            mn = min(mn, mid);
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    return find_i(mn);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    ot.resize(m);
    for (auto &el: ot) {
        cin >> el;
    }

    cout << sol();

    return 0;
}