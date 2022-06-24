#include <bits/stdc++.h>

using namespace std;

int s, c;
vector<int> in;

long long cnt(int l) {
    long long ret = 0;
    int cnt = 0;

    for (auto el: in) {
        ret += el % l;
        cnt += el / l;
    }

    ret += (cnt - c) * l;

    return ret;
}

int find_max() {
    int ret = 1;
    for (auto el: in) {
        ret = max(el, ret);
    }
    return ret;
}

bool is_avail(int l) {
    int cnt = 0;

    for (auto el: in) {
        cnt += el / l;
    }

    return cnt >= c;
}

long long sol() {
    int l = 1, r = find_max() + 1;
    int mx = 1;

    while (l < r) {
        int mid = (l + r) / 2;
        if (is_avail(mid)) {
            l = mid + 1;
            mx = max(mx, mid);
        } else {
            r = mid;
        }
    }

    return accumulate(in.begin(), in.end(), 0ll) - (long)mx * (long)c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> s >> c;
    in.resize(s);
    for (auto &el: in) {
        cin >> el;
    }

    cout << sol();

    return 0;
}