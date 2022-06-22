#include <bits/stdc++.h>

using namespace std;

int n;

int sol() {
    int cand = 1;
    int ret = 1;

    while (cand % n != 0) {
        cand %= n;
        cand = 10 * cand + 1;
        ++ret;
    }

    return ret;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (cin >> n) {
        cout << sol() << '\n';
    }

    return 0;
}