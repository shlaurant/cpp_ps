#include <bits/stdc++.h>

using namespace std;

int _subp[6] = {0, 5, 5, 5, 5, 5};
vector<int> paper;

int find_next_1(int begin) {
    if (begin >= 100) return -1;
    for (auto i = begin; i < 100; ++i) {
        if (paper[i] == 1) return i;
    }
    return -1;
}

bool is_good(int index, int sz) {
    if (index / 10 + sz > 10 || index % 10 + sz > 10) return false;

    for (auto i = index; i < index + sz; ++i) {
        for (auto j = 0; j < sz; ++j) {
            if (paper[i + 10 * j] == 0) return false;
        }
    }

    return true;
}

void set_yx(int index, int sz, int val) {
    for (auto i = index; i < index + sz; ++i) {
        for (auto j = 0; j < sz; ++j) {
            paper[i + 10 * j] = val;
        }
    }
}

void dfs(int index, int cnt, int &ret) {
    if (index == -1) {
        ret = min(cnt, ret);
        return;
    }
    if (cnt >= ret) return;

    ++cnt;

    for (auto i = 5; i > 0; --i) {
        if (is_good(index, i) && _subp[i] > 0) {
            set_yx(index, i, 0);
            --_subp[i];
            dfs(find_next_1(index + i), cnt, ret);
            ++_subp[i];
            set_yx(index, i, 1);
        }
    }

    --cnt;
}
int sol() {
    int ret = INT_MAX;

    dfs(find_next_1(0), 0, ret);

    return ret == INT_MAX ? -1 : ret;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    paper.resize(100);

    for (auto &el: paper) {
        cin >> el;
    }

    cout << sol();
}