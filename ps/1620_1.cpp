//1523
#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<string> v;
map<string, int> mp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    v.resize(n + 1);
    string str;
    for (auto i = 0; i < n; ++i) {
        cin >> str;
        v[i + 1] = str;
        mp[str] = i + 1;
    }

    for (auto i = 0; i < m; ++i) {
        cin >> str;
        if (isalpha(str[0])) {
            cout << mp[str] << '\n';
        } else {
            cout << v[stoi(str)] << '\n';
        }
    }

    return 0;
}