#include <bits/stdc++.h>

using namespace std;

int a, b, c, d;

map<pair<int, int>, int> mp;
queue<pair<int, int>> q;

void f(const pair<int, int> p, queue<pair<int, int>> &q) {
    auto cv = mp[p];
    if (mp[{p.first, b}] == 0) {
        q.push({p.first, b});
        mp[{p.first, b}] = cv + 1;
    }

    if (mp[{a, p.second}] == 0) {
        q.push({a, p.second});
        mp[{a, p.second}] = cv + 1;
    }
}

void e(const pair<int, int> p, queue<pair<int, int>> &q) {
    auto cv = mp[p];
    if (mp[{p.first, 0}] == 0) {
        q.push({p.first, 0});
        mp[{p.first, 0}] = cv + 1;
    }

    if (mp[{0, p.second}] == 0) {
        q.push({0, p.second});
        mp[{0, p.second}] = cv + 1;
    }
}

void m(const pair<int, int> p, queue<pair<int, int>> &q) {
    auto cv = mp[p];
    if (mp[{min(a, p.first + p.second), p.first + p.second -
                                        min(a, p.first + p.second)}] == 0) {
        q.push({min(a, p.first + p.second),
                p.first + p.second - min(a, p.first + p.second)});
        mp[{min(a, p.first + p.second), p.first + p.second -
                                        min(a, p.first + p.second)}] = cv + 1;
    }

    if (mp[{p.first + p.second - min(b, p.first + p.second),
            min(b, p.first + p.second)}] == 0) {
        q.push({p.first + p.second - min(b, p.first + p.second),
                min(b, p.first + p.second)});
        mp[{p.first + p.second - min(b, p.first + p.second),
            min(b, p.first + p.second)}] = cv + 1;
    }
}

void tab() {
    q.push({0, 0});
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        f(cur, q);
        e(cur, q);
        m(cur, q);
    }
}

int sol() {
    if (0 < c && c < a && 0 < d && d < b) return -1;

    mp[{0, 0}] = 1;

    tab();

    return mp[{c, d}] == 0 ? -1 : mp[{c, d}] - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b >> c >> d;

    cout << sol();

    return 0;
}