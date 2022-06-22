#include <bits/stdc++.h>

using namespace std;

string str;

typedef string::const_iterator iter;

bool sol() {
    iter b;
    int cnt = 0;
    b = str.begin();

    while (b != str.end()) {
        if (cnt + 2 > str.size()) return false;
        if (string(b, b + 2) == "pi" || string(b, b + 2) == "ka") {
            b += 2;
            cnt += 2;
        } else {
            if (cnt + 3 > str.size()) return false;
            if (string(b, b + 3) != "chu") return false;
            b += 3;
            cnt += 3;
        }
    }

    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> str;

    sol() ? cout << "YES" : cout << "NO";

    return 0;
}