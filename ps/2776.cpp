#include <bits/stdc++.h>

using namespace std;

int t, n, m;

vector<int> n1;
vector<int> n2;

bool do_exist(int i) {
    int l = 0, r = n1.size();
    while (l < r) {
        auto mid = (l + r) / 2;
        if (n1[mid] == i) {
            return true;
        } else if (n1[mid] > i) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return false;
}

void sol() {
    sort(n1.begin(), n1.end());
    for (auto &el: n2) {
        do_exist(el) ? el = 1 : el = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;

    for (auto i = 0; i < t; ++i) {
        n1.clear();
        n2.clear();

        cin >> n;
        n1.resize(n);
        for (auto &el: n1) {
            cin >> el;
        }

        cin >> m;
        n2.resize(m);
        for (auto &el: n2) {
            cin >> el;
        }

        sol();

        for (auto el: n2) {
            cout << el << '\n';
        }
    }

    return 0;
}