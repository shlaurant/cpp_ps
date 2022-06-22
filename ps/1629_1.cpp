#include <bits/stdc++.h>

using namespace std;

long long sol(int a, int b, int c) {
    if (b == 1) return a%c;

    long long ret = sol(a, b / 2, c);
    ret *= ret;
    ret %= c;
    if (b % 2 == 1) {
        ret *= a;
        ret %= c;
    }
    return ret;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;

    cin >> a >> b >> c;
    cout << sol(a, b, c);
    return 0;
}