#include <bits/stdc++.h>

using namespace std;

int m[10][10];
int p[5] = {5, 5, 5, 5, 5};
int ans = INT_MAX;

bool not_removable(int i, int j, int k) {
    if (i + k >= 10 || j + k >= 10) return true;
    for (auto y = i; y <= i + k; ++y) {
        for (auto x = j; x <= j + k; ++x) {
            if (m[y][x] == 0) {
                return true;
            }
        }
    }
    return false;
}

void set_sq(int i, int j, int k, int v) {
    for (auto y = i; y <= i + k; ++y) {
        for (auto x = j; x <= j + k; ++x) {
            m[y][x] = v;
        }
    }
}

void sol2(int y, int x, int cnt) {
    if (cnt >= ans) return;
    if (x == 10) {
        sol2(y + 1, 0, cnt);
        return;
    }
    if (y == 10) {
        ans = min(cnt, ans);
    }
    if (m[y][x] == 0) {
        sol2(y, x + 1, cnt);
        return;
    }
    for (auto k = 4; k >= 0; --k) {
        if (p[k] < 1 || not_removable(y, x, k)) continue;
        set_sq(y, x, k, 0);
        --p[k];
        sol2(y, x + k + 1, ++cnt);
        --cnt;
        ++p[k];
        set_sq(y, x, k, 1);
    }
    return;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    for (auto i = 0; i < 100; ++i) {
        cin >> m[i / 10][i % 10];
    }

    sol2(0, 0, 0);
    ans == INT_MAX ? cout << -1 : cout << ans;
    return 0;
}