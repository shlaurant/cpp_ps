#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    cin >> str;

    while (!str.empty()) {
        if (string(str.begin(), str.begin() + 2) == "pi") {
            str.erase(str.begin(), str.begin() + 2);
        } else if (string(str.begin(), str.begin() + 2) == "ka") {
            str.erase(str.begin(), str.begin() + 2);
        } else if (string(str.begin(), str.begin() + 3) == "chu") {
            str.erase(str.begin(), str.begin() + 3);
        } else {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

    return 0;
}