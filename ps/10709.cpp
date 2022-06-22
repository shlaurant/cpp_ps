#include <bits/stdc++.h>

using namespace std;

int sy, sx, r[100][100];
char m[100][100];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> sy >> sx;

    for (auto i = 0; i < sy; ++i) {
        for (auto j = 0; j < sx; ++j) {
            cin >> m[i][j];
        }
    }

    for (auto i = 0; i < sy; ++i) {
        int d = -1;
        for (auto j = 0; j < sx; ++j) {
            if (m[i][j] == 'c') {
                d = 0;
                r[i][j] = d;
            } else {
                if (d != -1) ++d;
                r[i][j] = d;
            }
        }
    }

    for (auto i = 0; i < sy; ++i) {
        for (auto j = 0; j < sx; ++j) {
            cout << r[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}