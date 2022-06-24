#include <bits/stdc++.h>

using namespace std;

long long x, y;

long long sol() {
    long long ret = 0;

    long long init = y * 100 / x;
    long long l = 0, r = 1e9 + 1;
    while (l < r) {
        auto mid = (l + r) / 2;
        if ((y + mid) * 100 / (x + mid) > init) {
            ret = mid;
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    return ret == 0 ? -1 : ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> x >> y;

    cout << sol();

    return 0;
}