#include <bits/stdc++.h>

using namespace std;

struct Tuple {
    int r, c, s, i;
};

typedef Tuple tp;

int r, c, k;
vector<vector<int>> arr;
vector<tp> rot;

vector<vector<int>> ori;

bool comp(const tp &l, const tp &r) {
    return l.i < r.i;
}

void _rot(int y, int x, int sz) {
    vector<pair<int, int>> vec;
    for (auto tx = x - sz; tx <= x + sz; ++tx) {
        vec.push_back({y - sz, tx});
    }
    for (auto ty = y - sz + 1; ty < y + sz; ++ty) {
        vec.push_back({ty, x + sz});
    }
    for (auto tx = x + sz; tx >= x - sz; --tx) {
        vec.push_back({y + sz, tx});
    }
    for (auto ty = y + sz - 1; ty > y - sz; --ty) {
        vec.push_back({ty, x - sz});
    }

    int temp = arr[vec[0].first][vec[0].second];
    int temp2;
    for (auto i = 1; i < vec.size(); ++i) {
        temp2 = arr[vec[i].first][vec[i].second];
        arr[vec[i].first][vec[i].second] = temp;
        temp = temp2;
    }
    arr[vec[0].first][vec[0].second] = temp;
}

void do_rotation(const tp &el) {
    for (auto s = 1; s <= el.s; ++s) {
        _rot(el.r, el.c, s);
    }
}

int cnt_arr() {
    int ret = INT_MAX;
    for (const auto &rw: arr) {
        ret = min(ret, accumulate(rw.begin(), rw.end(), 0));
    }
    return ret;
}

int sol() {
    int ret = INT_MAX;

    sort(rot.begin(), rot.end(), comp);

    ori = arr;

    do {
        arr = ori;
        for (const auto &el: rot) {
            do_rotation(el);
        }
        ret = min(ret, cnt_arr());
    } while (next_permutation(rot.begin(), rot.end(), comp));

    return ret;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c >> k;
    arr.resize(r, vector<int>(c));
    for (auto &rw: arr) {
        for (auto &el: rw) {
            cin >> el;
        }
    }

    int cnt = 0;
    for (auto i = 0; i < k; ++i) {
        tp t;
        cin >> t.r >> t.c >> t.s;
        t.r -= 1;
        t.c -= 1;
        t.i = cnt;
        rot.push_back(t);
        ++cnt;
    }

    cout << sol();

    return 0;
}