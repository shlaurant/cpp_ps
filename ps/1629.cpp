#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll mult(ll a, ll b, ll c) {
    if (b == 1) return a % c;
    ll ret = mult(a, b / 2, c);
    ret *= ret;
    ret %= c;
    if (b & 1) {
        ret *= a;
        ret %= c;
    }
    return ret;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    long long ret = 1;
    int a, b, c;

    cin >> a;
    cin >> b;
    cin >> c;

    cout << mult(a, b, c);

    return 0;
}