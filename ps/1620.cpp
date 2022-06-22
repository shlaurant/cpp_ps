#include <bits/stdc++.h>

using namespace std;

int main() {
    cout.tie(NULL);
    cin.tie(NULL);

    int n, m;
    cin >> n;
    cin >> m;

    vector<string> dic(n);
    unordered_map<string, int> mdic;

    for (auto i = 0; i < n; ++i) {
        cin >> dic[i];
        mdic[dic[i]] = i;
    }

    for (auto i = 0; i < m; ++i) {
        string input;
        cin >> input;
        if (isalpha(input[0])) {
            cout << mdic[input] + 1 << "\n";
        } else {
            cout << dic[stoi(input) - 1] << "\n";
        }
    }
}