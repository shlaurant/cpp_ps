#include <bits/stdc++.h>

using namespace std;

int n, m, j, ret = 0, cb = 0, ca;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> j;

    for (auto i = 0; i < j; ++i) {
        cin >> ca;
        if (cb < ca && ca <= cb + m) continue;
        if (ca <= cb) {
            ret += cb - ca + 1;
            cb -= cb - ca + 1;
        } else {
            ret += ca - cb - m;
            cb += ca - cb - m;
        }
    }

    cout << ret;
    return 0;
}