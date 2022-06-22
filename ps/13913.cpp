#include <bits/stdc++.h>

using namespace std;

int n, k;

void move(int x, int (&nx)[3]) {
    nx[0] = x - 1;
    nx[1] = x + 1;
    nx[2] = 2 * x;
}

void bfs(int init, vector<int> &v, vector<int> &tr) {
    queue<int> q;
    v[init] = 0;
    tr[init] = init;
    q.push(init);

    int x, nx[3];

    while (!q.empty()) {
        x = q.front();
        q.pop();
        if (x == k) return;
        if (v[k] <= v[x]) continue;
        move(x, nx);
        for (auto _nx: nx) {
            if (_nx < 0 || _nx > 100000 || v[_nx] != INT_MAX) continue;
            v[_nx] = v[x] + 1;
            tr[_nx] = x;
            q.push(_nx);
        }
    }
}

void sol(int &t, string &s) {
    vector<int> v(100001);
    vector<int> tr(100001);
    fill(v.begin(), v.end(), INT_MAX);
    fill(tr.begin(), tr.end(), INT_MAX);
    bfs(n, v, tr);
    t = v[k];

    vector<int> p;
    int i = k;
    while (true) {
        p.push_back(i);
        if (i == n) break;
        i = tr[i];
    }
    reverse(p.begin(), p.end());
    for (auto el: p) {
        s += to_string(el) + " ";
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    int t = 0;
    string s;
    sol(t, s);
    cout << t << '\n' << s;
}