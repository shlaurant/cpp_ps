#include <bits/stdc++.h>

using namespace std;

int r, c;

pair<int, int> j, cr;
vector<vector<char>> cl;
vector<vector<bool>> v;

void make_move(const pair<int, int> &p, pair<int, int> (&np)[4]) {
    np[0] = {p.first - 1, p.second};
    np[1] = {p.first, p.second + 1};
    np[2] = {p.first + 1, p.second};
    np[3] = {p.first, p.second - 1};
}

bool over_bound(const pair<int, int> &p) {
    return p.first < 0 || p.first >= r || p.second < 0 || p.second >= c;
}

int sol() {
    int ret = 0;
    v.resize(r, vector<bool>(c));
    v[j.first][j.second] = true;
    queue<pair<int, int>> q;
    q.push(j);

    while (!v[cr.first][cr.second]) {
        ++ret;
        queue<pair<int, int>> temp;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            pair<int, int> np[4];
            make_move(p, np);
            for (const auto &el: np) {
                if (over_bound(el) || v[el.first][el.second]) continue;
                if (cl[el.first][el.second] == '0') {
                    v[el.first][el.second] = true;
                    q.push(el);
                } else if (cl[el.first][el.second] == '1') {
                    temp.push(el);
                    v[el.first][el.second] = true;
                } else {
                    v[el.first][el.second] = true;
                    return ret;
                }
            }
        }
        swap(temp, q);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c;
    cin >> j.first >> j.second >> cr.first >> cr.second;
    j.first--;
    j.second--;
    cr.first--;
    cr.second--;
    cl.resize(r, vector<char>(c));
    for (auto &rw: cl) {
        for (auto &el: rw) {
            cin >> el;
        }
    }

    cout << sol();

    return 0;
}