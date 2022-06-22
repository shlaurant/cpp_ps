#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<char>> paper;

int acc_ver(int yb, int x, int sz) {
    int ret = 0;

    for (auto i = yb; i < yb + sz; ++i) {
        ret += paper[i][x] - '0';
    }

    return ret;
}

int acc_hor(int xb, int y, int sz) {
    int ret = 0;

    for (auto i = xb; i < xb + sz; ++i) {
        ret += paper[y][i] - '0';
    }

    return ret;
}

int rec(int yb, int ye, int xb, int xe) {
    if(ye == yb || xb == xe) return 0;
    if (ye - yb == 1) return acc_hor(xb, yb, xb - xe);
    if (xe - xb == 1) return acc_ver(yb, xb, ye - yb);

    int mx_y_i = yb, mx_y_v = paper[yb][xb] - '0';
    for (auto i = yb; i < ye; ++i) {
        if (mx_y_v < paper[i][xb] - '0') {
            mx_y_v = paper[i][xb] - '0';
            mx_y_i = i;
        }
    }

    int mx_x_i = yb, mx_x_v = paper[yb][xb] - '0';
    for (auto i = xb; i < xe; ++i) {
        if (mx_x_v < paper[yb][i] - '0') {
            mx_x_v = paper[yb][i] - '0';
            mx_x_i = i;
        }
    }

    int a, b;
    int cura = acc_hor(xb, mx_y_v, xe - xb);
    a = cura + max(rec(yb, mx_y_i, xb, xe), rec(mx_y_i + 1, ye, xb, xe));
    int curb = acc_ver(yb, mx_x_i, ye - yb);
    b = curb + max(rec(yb, ye, xb, mx_x_i), rec(yb, ye, mx_x_i + 1, xe));

    return max(a, b);
}

int sol() {
    return rec(0, n, 0, m);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m;
    paper.resize(n, vector<char>(m));
    for (auto &rw: paper) {
        for (auto &el: rw) {
            cin >> el;
        }
    }

    cout << sol();

    return 0;
}