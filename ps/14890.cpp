#include <bits/stdc++.h>

using namespace std;

typedef vector<int>::const_iterator iter;

int n, l;
vector<vector<int>> mp;

vector<pair<int, int>> slope;
vector<bool> v;

bool is_good(const vector<int> &road) {
    slope.clear();
    iter b, e;
    b = road.begin();
    while (b != road.end()) {
        e = find_if(b, road.cend(), [b](int h) -> bool { return *b != h; });
        if (e != road.end()) {
            if (abs(*b - *e) > 1) return false;
            if (*b - *e == 1) {
                b = e;
                e = find_if(b, road.cend(),
                            [b](int h) -> bool { return *b != h; });
                slope.push_back({e - 1 - road.begin(), b - 1 - road.begin()});
            } else {
                slope.push_back({b - road.begin(), e - road.begin()});
                b = e;
            }
        } else {
            b = e;
        }
    }

    fill(v.begin(), v.end(), false);
    for (const auto &el: slope) {
        if (abs(el.first - el.second) < l) return false;
        for (auto i = 0; i < l; ++i) {
            if (el.second - el.first > 0) {
                if (v[el.second - 1 - i]) return false;
                v[el.second - 1 - i] = true;
            } else {
                if (v[el.second + 1 + i]) return false;
                v[el.second + 1 + i] = true;
            }

        }
    }
    return true;
}

int print(const vector<int> &road) {
    for (auto el: road) {
        cout << el << ' ';
    }
}

int sol() {
    int ret = 0;
    v.resize(n);

    vector<int> road(n);
    for (const auto &rw: mp) {
        copy(rw.begin(), rw.end(), road.begin());
        if (is_good(road)) ++ret;
    }

    for (auto i = 0; i < n; ++i) {
        road.clear();
        for (const auto &rw: mp) {
            road.push_back(rw[i]);
        }
        if (is_good(road)) ++ret;
    }

    return ret;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l;
    mp.resize(n, vector<int>(n));
    for (auto &rw: mp) {
        for (auto &el: rw) {
            cin >> el;
        }
    }

    cout << sol();
}