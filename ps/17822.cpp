#include <bits/stdc++.h>

using namespace std;

struct rt {
    int x, d, k;
};

int n, m, t;
vector<vector<int>> circles;
vector<rt> rots;

void _rtc(vector<int> &circle, int dist) {
    for (auto i = 0; i < dist; ++i) {
        vector<int> temp;
        temp.push_back(circle.back());
        copy(circle.begin(), --circle.end(), back_inserter(temp));
        circle = temp;
    }
}

void _rtcc(vector<int> &circle, int dist) {
    for (auto i = 0; i < dist; ++i) {
        vector<int> temp;
        copy(++circle.begin(), circle.end(), back_inserter(temp));
        temp.push_back(circle.front());
        circle = temp;
    }
}

void _rotate(int index, int dir, int dist) {
    dir == 0 ? _rtc(circles[index], dist) : _rtcc(circles[index], dist);
}

void rotate(const rt &rt) {
    auto target = rt.x;
    while (target - 1 < n) {
        _rotate(target - 1, rt.d, rt.k);
        target += rt.x;
    }
}

bool check_hor(int i, int j) {
    int l = j - 1, r = j + 1;
    if (l < 0) l = m - 1;
    if (r >= m) r = 0;
    return circles[i][j] == circles[i][r] || circles[i][j] == circles[i][l];
}

bool check_ver(int i, int j) {
    if (i - 1 >= 0) {
        if (circles[i][j] == circles[i - 1][j]) return true;
    }
    if (i + 1 < n) {
        if (circles[i][j] == circles[i + 1][j]) return true;
    }
    return false;
}

bool remove() {
    bool ret = false;
    vector<pair<int, int>> to_rm;
    for (auto i = 0; i < n; ++i) {
        for (auto j = 0; j < m; ++j) {
            if (circles[i][j] == 0) continue;
            if (check_hor(i, j)) {
                to_rm.push_back({i, j});
                continue;
            }
            if (check_ver(i, j)) to_rm.push_back({i, j});
        }
    }
    ret = !to_rm.empty();

    for (const auto &el: to_rm) {
        circles[el.first][el.second] = 0;
    }

    return ret;
}

void averize() {
    int cnt = 0;
    int sum = 0;
    for (const auto &rw: circles) {
        for (const auto &el: rw) {
            sum += el;
            if (el != 0) ++cnt;
        }
    }
    if (cnt == 0) return;
    int avg = sum / cnt;

    for (auto &rw: circles) {
        for (auto &el: rw) {
            if (el == 0) continue;
            if (avg < el) --el;
            else if (avg > el) ++el;
            else if (sum % cnt != 0) ++el;
        }
    }
}

int sum() {
    int sum = 0;
    for (const auto &rw: circles) {
        for (const auto &el: rw) {
            sum += el;
        }
    }
    return sum;
}

int sol() {
    for (const auto &el: rots) {
        rotate(el);
        if (!remove()) averize();
    }
    return sum();
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> t;
    circles.resize(n, vector<int>(m));
    for (auto &rw: circles) {
        for (auto &el: rw) {
            cin >> el;
        }
    }

    rots.resize(t);
    for (auto &el: rots) {
        cin >> el.x >> el.d >> el.k;
    }

    cout << sol();

    return 0;
}