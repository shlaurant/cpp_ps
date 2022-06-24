#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> cost;

int max_cost() {
    int ret = 0;

    for (auto el: cost) {
        if (ret < el) ret = el;
    }

    return ret;
}

int count(int p) {
    int ret = 0;
    int left = 0;

    for (auto el: cost) {
        if (left < el) {
            ++ret;
            left = p;
        }
        left -= el;
    }

    return ret;
}

int sol() {
    int ret = INT_MAX;

    int l = max_cost(), r = accumulate(cost.begin(), cost.end(), 0) + 1;
    while (l < r) {
        int mid = (l + r) / 2;
        int cnt = count(mid);
        if (cnt > m) {
            l = mid + 1;
        } else {
            ret = min(ret, mid);
            r = mid;
        }
    }

    return ret;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    cost.resize(n);
    for (auto &el: cost) {
        cin >> el;
    }

    cout << sol();

    return 0;
}