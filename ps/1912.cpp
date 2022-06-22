#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> p;

int sol() {
    int ret = INT_MIN;

    int l = 0, r = 1, sum = p[0];
    while (r < p.size()) {
        ret = max(ret, sum);
        if (sum <= 0) {
            l = r;
            r = l + 1;
            sum = p[l];
        } else {
            sum += p[r];
            ++r;
        }
    }
    ret = max(ret, sum);

    return ret;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    p.resize(n);
    for (auto &el: p) {
        cin >> el;
    }

    cout << sol();

    return 0;
}