#include <bits/stdc++.h>

using namespace std;

int t;

int operate(char op, list<int> &l, bool &rev) {
    if (op == 'R') {
        rev = !rev;
    } else {
        if (l.empty()) return 1;
        rev ? l.erase(--l.end()) : l.erase(l.begin());
    }
    return 0;
}

void sol(const string &p, int cnt, list<int> &l) {
    bool rev = false;
    for (auto op: p) {
        if (operate(op, l, rev)) {
            cout << "error" << '\n';
            return;
        }
    }
    cout << '[';
    if (rev) {
        auto i = l.rbegin();
        while (i != l.rend()) {
            cout << *i;
            if (i != --l.rend()) cout << ',';
            ++i;
        }
    } else {
        auto i = l.begin();
        while (i != l.end()) {
            cout << *i;
            if (i != --l.end()) cout << ',';
            ++i;
        }
    }
    cout << "]\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    for (auto i = 0; i < t; ++i) {
        string p;
        int n;
        char c;
        cin >> p >> n;
        list<int> l(n);
        for (auto &el: l) {
            cin >> c >> el;
        }
        cin >> c;
        if (n == 0) cin >> c;
        sol(p, n, l);
    }

    return 0;
}