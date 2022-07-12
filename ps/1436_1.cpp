//1433
#include <bits/stdc++.h>

using namespace std;

int n;

int sol() {
    int ret = 0;
    int cnt = 0;
    while (cnt < n) {
        ++ret;
        auto it = to_string(ret).find("666");
        if (it != string::npos) ++cnt;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    cout << sol();

    return 0;
}