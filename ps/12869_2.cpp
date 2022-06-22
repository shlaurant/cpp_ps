#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> hp;

int v[61][61][61];

struct Tuple {
    Tuple() : a(0), b(0), c(0) {}
    Tuple(int a, int b, int c) : a(a), b(b), c(c) {}

    int a, b, c;
};

typedef Tuple tp;

tp dp[6] = {tp(9, 3, 1), tp(9, 1, 3), tp(3, 9, 1), tp(3, 1, 9), tp(1, 9, 3),
            tp(1, 3, 9)};

tp _minus(const tp &l, const tp &r) {
    return tp(max(0, l.a - r.a), max(0, l.b - r.b), max(0, l.c - r.c));
}

void make_np(tp cur, tp (&np)[6]) {
    np[0] = _minus(cur, dp[0]);
    np[1] = _minus(cur, dp[1]);
    np[2] = _minus(cur, dp[2]);
    np[3] = _minus(cur, dp[3]);
    np[4] = _minus(cur, dp[4]);
    np[5] = _minus(cur, dp[5]);
}

void bfs(const vector<int> &sp) {
    queue<tp> q;
    q.push(tp(sp[0], sp[1], sp[2]));
    v[sp[0]][sp[1]][sp[2]] = 1;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        tp np[6];
        make_np(cur, np);
        for (const auto &el: np) {
            if (!v[el.a][el.b][el.c]) {
                v[el.a][el.b][el.c] = v[cur.a][cur.b][cur.c] + 1;
                q.push(el);
            }
        }
        if (v[0][0][0]) return;
    }
}

int sol() {
    fill((&v)[0][0][0], (&v)[0][0][0] + 226981, 0);
    bfs(hp);
    return v[0][0][0] - 1;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    hp.resize(3);
    for (auto i = 0; i < n; ++i) {
        cin >> hp[i];
    }

    cout << sol();

    return 0;
}