#include <bits/stdc++.h>

using namespace std;

int m;
int s = 0;

void sol(const string &cmd, int arg) {
    if (cmd == "add") {
        s |= 1 << arg;
    } else if (cmd == "remove") {
        s &= ~(1 << arg);
    } else if (cmd == "check") {
        s & 1 << arg ? cout << 1 << '\n' : cout << 0 << '\n';
    } else if (cmd == "toggle") {
        s ^= 1 << arg;
    } else if (cmd == "all") {
        s = (1 << 21) - 1;
    } else if (cmd == "empty") {
        s = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m;
    string cmd;
    int arg;

    for (auto i = 0; i < m; ++i) {
        cin >> cmd;
        if (cmd != "all" && cmd != "empty") {
            cin >> arg;
        }

        sol(cmd, arg);
    }

    return 0;
}