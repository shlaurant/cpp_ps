#include <bits/stdc++.h>

using namespace std;

int r, c;
vector<vector<int>> paper;

vector<vector<bool>> v;

int _count(int y, int x, int i) {
    bool is_hor = i & 1 << (x + y * c);
    int ret = paper[y][x];
    v[y][x] = true;
    if (is_hor) {
        for (auto nx = x + 1; nx < c; ++nx) {
            if (!(i & 1 << (nx + y * c))) break;
            ret *= 10;
            ret += paper[y][nx];
            v[y][nx] = true;
        }
    } else {
        for (auto ny = y + 1; ny < r; ++ny) {
            if (i & 1 << (x + ny * c)) break;
            ret *= 10;
            ret += paper[ny][x];
            v[ny][x] = true;
        }
    }
    return ret;
}

int count(int i) {
    int ret = 0;

    for (auto y = 0; y < r; ++y) {
        for (auto x = 0; x < c; ++x) {
            if (!v[y][x]) ret += _count(y, x, i);
        }
    }

    return ret;
}

int sol() {
    int ret = 0;
    v.resize(r, vector<bool>(c));

    for (auto i = 0; i < 1 << r * c; ++i) {
        for (auto &rw: v) {
            fill(rw.begin(), rw.end(), false);
        }
        ret = max(ret, count(i));
    }

    return ret;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c;
    paper.resize(r, vector<int>(c));
    for (auto &rw: paper) {
        for (auto &el: rw) {
            char c;
            cin >> c;
            el = c - '0';
        }
    }

    cout << sol();

    return 0;
}