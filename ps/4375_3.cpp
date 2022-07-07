#include <bits/stdc++.h>

using namespace std;

int sol(int n) {
    int target = 1;
    int cnt = 1;
    while (target % n != 0) {
        target *= 10;
        ++target;
        target %= n;
        ++cnt;
    }
    return cnt;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    while (cin >> n) {
#ifndef ONLINE_JUDGE
        if (n == 0) break;
#endif
        cout << sol(n) << '\n';
    }

    return 0;
}