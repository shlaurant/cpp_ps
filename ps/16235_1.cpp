#include <bits/stdc++.h>

using namespace std;

struct node {
    int nut = 5;
    deque<int> tree;
};

int n, m, k;

vector<vector<node>> re;
vector<vector<int>> a;

int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void _ss(node &nd) {
    auto it = nd.tree.begin();
    while (it != nd.tree.end()) {
        if (*it > nd.nut) {
            break;
        } else {
            nd.nut -= *it;
            *it += 1;
            ++it;
        }
    }

    auto b = it;
    while (it != nd.tree.end()) {
        nd.nut += *it / 2;
        ++it;
    }
    nd.tree.erase(b, it);
}

void spring_summer() {
    for (auto y = 0; y < n; ++y) {
        for (auto x = 0; x < n; ++x) {
            _ss(re[y][x]);
        }
    }
}

void _fw(int y, int x) {
    int cnt = 0;
    for (auto el: re[y][x].tree) {
        if (el % 5 == 0) cnt++;
    }
    for (auto i = 0; i < 8; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        for (auto j = 0; j < cnt; ++j) re[ny][nx].tree.push_front(1);
    }
    re[y][x].nut += a[y][x];
}

void fall_winter() {
    for (auto y = 0; y < n; ++y) {
        for (auto x = 0; x < n; ++x) {
            _fw(y, x);
        }
    }
}

int count() {
    int ret = 0;
    for (const auto &rw: re) {
        for (const auto &el: rw) {
            ret += el.tree.size();
        }
    }
    return ret;
}

int sol() {
    for (auto i = 0; i < k; ++i) {
        spring_summer();
        fall_winter();
    }
    return count();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    a.resize(n, vector<int>(n));
    for (auto &rw: a) {
        for (auto &el: rw) {
            cin >> el;
        }
    }

    re.resize(n, vector<node>(n));
    for (auto i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        re[--x][--y].tree.push_back(z);
    }

    cout << sol();

    return 0;
}