#include <bits/stdc++.h>

using namespace std;

int n, k;
pair<int, int> n_pair = pair<int, int>(INT_MAX, 0);

void move(int x, int (&nx)[3]) {
    nx[0] = x - 1;
    nx[1] = x + 1;
    nx[2] = 2 * x;
}

void bfs(int init, pair<int, int> (&v)[100001]) {
    queue<int> q;
    v[init] = {0, 1};
    q.push(init);

    int x, nx[3];

    while (!q.empty()) {
        x = q.front();
        q.pop();
        if (v[k] != n_pair && v[k].first <= v[x].first) continue;
        move(x, nx);
        for (auto _nx: nx) {
            if (_nx < 0 || _nx > 100000) continue;
            if (v[_nx].first == v[x].first + 1) {
                ++v[_nx].second;
                q.push(_nx);
            } else if (v[_nx].first > v[x].first + 1) {
                v[_nx] = {v[x].first + 1, 1};
                q.push(_nx);
            }
        }
    }
}

void sol(int &t, int &c) {
    pair<int, int> v[100001];
    fill(v, v + 100001, n_pair);
    bfs(n, v);
    t = v[k].first;
    c = v[k].second;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    int t, c;
    sol(t, c);
    cout << t << '\n' << c;
}