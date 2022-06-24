#include <bits/stdc++.h>

using namespace std;

long long x, y;

long long sol() {
    long long q = x * x;
    long long p = x * 99 - y * 100;
    if (p <= 0) return -1;
    return q % p ? q / p + 1 : q / p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> x >> y;

    cout << sol();

    return 0;
}