#include <bits/stdc++.h>

using namespace std;

int r, c;
vector<vector<char>> lake;

pair<int, int> swans[2];
queue<pair<int, int>> ice;
queue<pair<int, int>> sq;
vector<vector<bool>> v;
vector<vector<bool>> iv;

void getPair(const pair<int, int> &p, pair<int, int> (&np)[4]) {
    np[0] = {p.first - 1, p.second};
    np[1] = {p.first, p.second + 1};
    np[2] = {p.first + 1, p.second};
    np[3] = {p.first, p.second - 1};
}

bool over_bound(const pair<int, int> &el) {
    return el.first < 0 || el.first >= r || el.second < 0 || el.second >= c;
}
void queue_ice() {
    for (auto y = 0; y < r; ++y) {
        for (auto x = 0; x < c; ++x) {
            if (lake[y][x] != 'X') continue;
            pair<int, int> np[4];
            getPair({y, x}, np);
            for (const auto &el: np) {
                if (over_bound(el))
                    continue;
                if (lake[el.first][el.second] != 'X') {
                    ice.push({y, x});
                    iv[y][x] = true;
                    break;
                }
            }

        }
    }
}

void visit() {
    queue<pair<int, int>> temp;
    while (!sq.empty()) {
        auto p = sq.front();
        sq.pop();
        pair<int, int> np[4];
        getPair({p.first, p.second}, np);
        for (const auto &el: np) {
            if (over_bound(el) || v[el.first][el.second]) continue;
            if (lake[el.first][el.second] == '.') {
                v[el.first][el.second] = true;
                sq.push(el);
            } else if (lake[el.first][el.second] == 'X') {
                v[el.first][el.second] = true;
                temp.push(el);
            } else {
                v[el.first][el.second] = true;
                return;
            }
        }
    }
    swap(temp, sq);
}

void melt_ice() {
    queue<pair<int, int>> temp;
    while (!ice.empty()) {
        auto p = ice.front();
        ice.pop();
        lake[p.first][p.second] = '.';
        pair<int, int> np[4];
        getPair(p, np);
        for (const auto &el: np) {
            if (over_bound(el)) continue;
            if (!iv[el.first][el.second] && lake[el.first][el.second] == 'X') {
                iv[el.first][el.second] = true;
                temp.push(el);
            }
        }
    }
    swap(temp, ice);
}

int sol() {
    int ret = 0;
    v.resize(r, vector<bool>(c));
    iv.resize(r, vector<bool>(c));
    queue_ice();
    sq.push(swans[0]);
    v[swans[0].first][swans[0].second] = true;

    visit();
    while (!v[swans[1].first][swans[1].second]) {
        melt_ice();
        visit();
        ++ret;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c;
    lake.resize(r, vector<char>(c));

    pair<int, int> *pp = swans;
    for (auto i = 0; i < r; ++i) {
        for (auto j = 0; j < c; ++j) {
            cin >> lake[i][j];
            if (lake[i][j] == 'L') {
                *pp = {i, j};
                ++pp;
            }
        }
    }

    cout << sol();

    return 0;
}