#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> jams;

int get_hi() {
    int ret = 0;
    for (auto el: jams) {
        ret = max(el, ret);
    }
    return ret;
}

bool avail(int num) {
    int least = 0;
    for (auto el: jams) {
        least += el / num;
        if (el % num > 0) ++least;
    }
    return n >= least;
}

int sol() {
    int ret = INT_MAX;

    int hi = get_hi() + 1;
    int low = 1;
    while (low < hi) {
        int mid = (hi + low) / 2;
        if (avail(mid)) {
            ret = min(ret, mid);
            hi = mid;
        } else {
            low = mid + 1;
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    jams.resize(m);
    for (auto &el: jams) {
        cin >> el;
    }

    cout << sol();

    return 0;
}