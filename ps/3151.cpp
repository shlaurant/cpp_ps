#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> seq;

int count(int l, int r, int target) {
    auto lb = lower_bound(seq.begin() + l, seq.begin() + r, target);
    auto ub = upper_bound(seq.begin() + l, seq.begin() + r, target);
    if (*lb != target) return 0;
    else return ub - lb;

}

long long sol() {
    long long ret = 0;

    sort(seq.begin(), seq.end());
    for (auto i = 0; i + 2 < n; ++i) {
        for (auto j = i + 1; j + 1 < n; ++j) {
            auto sum = seq[i] + seq[j];
            auto target = -sum;
            ret += count(j + 1, n, target);
        }
    }

    return ret;
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