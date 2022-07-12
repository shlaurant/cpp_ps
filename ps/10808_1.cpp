//2048
#include <bits/stdc++.h>

using namespace std;

vector<int> cnt(26);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    cin >> str;
    for (auto el: str) {
        ++cnt[el - 'a'];
    }

    for (auto el: cnt) {
        cout << el << ' ';
    }

    return 0;
}