#include <bits/stdc++.h>

using namespace std;

int n, x;
vector<int> p;

typedef vector<int>::const_iterator iter;

int sol() {
    if (p.size() == 1) return 0;

    int ret = 0;

    sort(p.begin(), p.end());
    iter i, j;
    i = p.begin();
    j = --p.end();

    while (i != j) {
        if (*i + *j > x) {
            --j;
        } else if (*i + *j < x) {
            ++i;
        } else {
            ++ret;
            if (*(j - 1) == *j) {
                --j;
            } else {
                ++i;
            }
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    p.resize(n);
    for (auto &el: p) {
        cin >> el;
    }
    cin >> x;

    cout << sol();

    return 0;
}