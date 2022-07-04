#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> seq;

vector<int> lis;

int sol() {
    lis.resize(n);
    auto end = lis.begin();
    for (auto el: seq) {
        auto it = lower_bound(lis.begin(), end, el);
        if (it == end) {
            *end = el;
            ++end;
        } else {
            if (*it > el) *it = el;
        }
    }
    return end - lis.begin();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    seq.resize(n);
    for (auto &el: seq) {
        cin >> el;
    }

    cout << sol();

    return 0;
}