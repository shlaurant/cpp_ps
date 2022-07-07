#include <bits/stdc++.h>

using namespace std;

struct quest {
    int s, i, p;
};

int n;
vector<quest> qv;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    qv.resize(n);
    for (auto &el: qv) {
        cin >> el.s >> el.i >> el.p;
    }

    return 0;
}