#include <bits/stdc++.h>

using namespace std;

int t, n;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    for (auto i = 0; i < t; ++i) {
        cin >> n;
        int ret = 0;

        for (auto j = 5; j <= n; j *= 5) {
            ret += n / j;
        }

        cout << ret << '\n';
    }

    return 0;
}