#include <bits/stdc++.h>

using namespace std;

int n, p[1000000], ans[1000000];
stack<int> s;

void solve() {
    fill(ans, ans + n, -1);
    for (auto i = 0; i < n; ++i) {
        while (!s.empty() && p[s.top()] < p[i]) {
            ans[s.top()] = p[i];
            s.pop();
        }
        s.push(i);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (auto i = 0; i < n; ++i) {
        cin >> p[i];
    }

    solve();

    for (auto i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}