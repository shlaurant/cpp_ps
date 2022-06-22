#include <bits/stdc++.h>

using namespace std;

int n, k;

vector<vector<bool>> v;

void next_p(int p, int (&np)[3]) {
    np[0] = p + 1;
    np[1] = p - 1;
    np[2] = 2 * p;
}

void mark_lv(queue<int> &q, int cnt) {
    queue<int> temp;
    while (!q.empty()) {
        int p = q.front();
        q.pop();

        int np[3];
        next_p(p, np);
        for (auto _np: np) {
            if (_np < 0 || _np > 500000) continue;
            if (v[cnt % 2][_np]) continue;
            v[cnt % 2][_np] = v[(cnt + 1) % 2][p] + 1;
            temp.push(_np);
        }
    }
    q = temp;
}

int sol() {
    int ret = INT_MAX;
    v.resize(2, vector<bool>(500001));
    queue<int> q;
    q.push(n);
    v[1][n] = true;
    int cnt = 1;
    do {
        if (v[cnt % 2][k]) return cnt - 1;
        mark_lv(q, cnt + 1);
        k += cnt;
        ++cnt;
    } while (k <= 500000);

    return ret;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    int ans = sol();
    ans > 500000 ? cout << -1 : cout << ans;
    return 0;
}