#include <bits/stdc++.h>

using namespace std;

int n;
int qt[64][64];

string quad_tree(int x, int y, int s) {
    int r = qt[y][x];

    for (auto i = x; i < x + s; ++i) {
        for (auto j = y; j < s + y; ++j) {
            if (qt[j][i] != r) {
                r = 2;
                break;
            }
        }
        if (r == 2) {
            break;
        }
    }

    if (r != 2) {
        return to_string(r);
    } else {
        return "(" + quad_tree(x, y, s / 2) + quad_tree(x + s / 2, y, s / 2) +
               quad_tree(x, y + s / 2, s / 2) +
               quad_tree(x + s / 2, y + s / 2, s / 2) + ")";
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (auto i = 0; i < n; ++i) {
        string str;
        cin >> str;
        for (auto j = 0; j < n; ++j) {
            qt[i][j] = str[j] - '0';
        }
    }

    cout << quad_tree(0, 0, n);
}