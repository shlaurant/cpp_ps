#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    int cnt;
    cin >> cnt;
    while (cnt--) {
        map<string, int> m;
        string s;
        int n;
        cin >> n;
        for (auto i = 0; i < n; i++) {
            cin >> s >> s;
            m[s]++;
        }
        int ret = 1;
        for (const auto &p: m) {
            ret *= p.second + 1;
        }
        cout << ret - 1 << "\n";
    }
}