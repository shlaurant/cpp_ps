#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    unordered_map<int, int> s;

    int n, m;
    cin >> n >> m;

    int ret = 0;

    for (auto i = 0; i < n; ++i) {
        int j;
        cin >> j;
        if (s[j] > 0) {
            ++ret;
            --s[j];
        } else {
            ++s[m-j];
        }
    }

    cout << ret;
    return 0;
}