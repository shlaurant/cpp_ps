#include <bits/stdc++.h>

using namespace std;

int n;
int ret;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    while (cin >> n) {
        ret = 1;
        int cand = 1;
        while (true) {
            if (cand % n == 0) {
                cout << ret << "\n";
                break;
            } else {
                cand *= 10;
                cand += 1;
                cand %= n;
                ret++;
            }
        }
    }

    return 0;
}