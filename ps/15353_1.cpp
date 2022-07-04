#include <bits/stdc++.h>

using namespace std;

string a, b;

string sol() {
    string ret;

    auto ait = a.rbegin();
    auto bit = b.rbegin();

    int carry = 0;
    while (ait != a.rend() || bit != b.rend()) {
        int val = carry;
        if (ait != a.rend()) {
            val += *ait - '0';
            ++ait;
        }
        if (bit != b.rend()) {
            val += *bit - '0';
            ++bit;
        }
        if (val / 10) {
            carry = 1;
            val %= 10;
        } else {
            carry = 0;
        }
        ret.insert(0, to_string(val));
    }
    if(carry) ret.insert(0, "1");

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b;

    cout << sol();

    return 0;
}