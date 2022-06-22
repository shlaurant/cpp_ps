#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> board;

void _shift(vector<int> &vec, int b, int e, int dir) {
    vector<bool> v(n);
    for (auto i = b; i != e; i += dir) {
        if (vec[i] == 0) continue;
        int j = i;
        while (j - dir >= 0 && j - dir < n && vec[j - dir] == 0) {
            vec[j - dir] = vec[j];
            vec[j] = 0;
            j -= dir;
        }
        if (j - dir < 0 && j - dir >= n) {
            //do nothing
        } else {
            if (!v[j - dir] && vec[j - dir] == vec[j]) {
                v[j - dir] = true;
                vec[j - dir] *= 2;
                vec[j] = 0;
            }
        }
    }
}

void shift_l() {
    for (auto i = 0; i < n; ++i) {
        _shift(board[i], 1, n, 1);
    }
}

void shift_r() {
    for (auto i = 0; i < n; ++i) {
        _shift(board[i], n - 2, -1, -1);
    }
}

void shift_u() {
    vector<int> vec(n);
    for (auto i = 0; i < n; ++i) {
        int t = 0;
        for (auto &el: vec) {
            el = board[t][i];
            ++t;
        }
        _shift(vec, 1, n, 1);
        t = 0;
        for (auto &el: vec) {
            board[t][i] = el;
            ++t;
        }
    }
}

void shift_d() {
    vector<int> vec(n);
    for (auto i = 0; i < n; ++i) {
        int t = 0;
        for (auto &el: vec) {
            el = board[t][i];
            ++t;
        }
        _shift(vec, n - 2, -1, -1);
        t = 0;
        for (auto &el: vec) {
            board[t][i] = el;
            ++t;
        }
    }
}

int find_max() {
    int mx = INT_MIN;

    for (const auto &rw: board) {
        for (auto el: rw) {
            mx = max(mx, el);
        }
    }

    return mx;
}

void dfs(int cnt, int &ret) {
    if (cnt == 5) {
        ret = max(ret, find_max());
        return;
    }
    ++cnt;
    vector<vector<int>> ori(board);

    shift_l();
    dfs(cnt, ret);
    board = ori;

    shift_u();
    dfs(cnt, ret);
    board = ori;

    shift_r();
    dfs(cnt, ret);
    board = ori;

    shift_d();
    dfs(cnt, ret);
    board = ori;

    --cnt;
}

int sol() {
    int ret = INT_MIN;

    dfs(0, ret);

    return ret;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    board.resize(n, vector<int>(n));
    for (auto &rw: board) {
        for (auto &el: rw) {
            cin >> el;
        }
    }

    cout << sol();

    return 0;
}