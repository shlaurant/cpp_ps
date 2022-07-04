#include <bits/stdc++.h>

using namespace std;

int m;
int s;

void sol(const string &cmd) {
    int x;

    if (cmd == "add") {
        cin >> x;
        s |= (1 << x);
    } else if (cmd == "remove") {
        cin >> x;
        s &= ~(1 << x);
    } else if (cmd == "check") {
        cin >> x;
        if (s & (1 << x)) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    } else if (cmd == "toggle") {
        cin >> x;
        s & (1 << x) ? s &= ~(1 << x) : s |= (1 << x);
    } else if (cmd == "all") {
        s = (1 << 21) - 1;
    } else{
        s = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> m;

    string cmd;

    for (auto i = 0; i < m; ++i) {
        cin >> cmd;
        sol(cmd);
    }

    return 0;
}