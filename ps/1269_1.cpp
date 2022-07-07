#include <bits/stdc++.h>

using namespace std;

int a, b;
vector<int> sa, sb;

int sub(const vector<int> &l, const vector<int> &r) {
    int ret = 0;
    auto ait = l.cbegin();
    auto bit = r.cbegin();
    while (ait != l.cend()) {
        if (bit != r.cend()) {
            if (*ait == *bit) {
                ++ait;
                ++bit;
            } else if (*ait > *bit) {
                ++bit;
            } else {
                ++ait;
                ++ret;
            }
        } else {
            ++ait;
            ++ret;
        }
    }
    return ret;
}

int sol() {
    sort(sa.begin(), sa.end());
    sort(sb.begin(), sb.end());

    return sub(sa, sb) + sub(sb, sa);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b;
    sa.resize(a);
    sb.resize(b);
    for (auto &el: sa) {
        cin >> el;
    }
    for (auto &el: sb) {
        cin >> el;
    }

    cout << sol();

    return 0;
}