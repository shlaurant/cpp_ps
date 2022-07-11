#include <bits/stdc++.h>

using namespace std;

vector<int> seq;
vector<int> q;

bool exist(int el) {
    int l = 0, r = seq.size();
    while (l < r) {
        auto mid = (l + r) / 2;
        if (seq[mid] == el) return true;
        else if (seq[mid] > el) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return false;
}

void sol() {
    sort(seq.begin(), seq.end());
    for (auto el: q) {
        if (exist(el)) {
            cout << 1;
        } else cout << 0;
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (auto i = 0; i < t; ++i) {
        int n, m;
        cin >> n;
        seq.resize(n);
        for (auto &el: seq) {
            cin >> el;
        }
        cin >> m;
        q.resize(m);
        for (auto &el: q) {
            cin >> el;
        }
        sol();
    }

    return 0;
}