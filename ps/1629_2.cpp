#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a, b, c;

ll rec(int b) {
    if (b == 1) return a % c;

    ll ret = rec(b / 2);
    ret *= ret;
    ret %= c;
    if (b % 2) {
        ret *= a;
        ret %= c;
    }

    return ret;
}

ll sol() {
    return rec(b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b >> c;

    cout << sol();

    return 0;
}