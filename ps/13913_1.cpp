#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> v_b;
vector<int> v;

void next_p(int p, int (&np)[3]) {
    np[0] = p + 1;
    np[1] = p - 1;
    np[2] = 2 * p;
}

int bfs(int s) {
    queue<int> q;
    q.push(s);
    v_b[s] = 1;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (cur == k) return cur;
        int np[3];
        next_p(cur, np);
        for (auto _np: np) {
            if (v_b[_np]) continue;
            if (0 <= _np && _np <= 100000) {
                v[_np] = cur;
                v_b[_np] = v_b[cur] + 1;
                q.push(_np);
            }
        }
    }
}

int sol() {
    return bfs(n);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    v.resize(100001);
    v[n] = -1;
    v_b.resize(100001);

    int last = sol();
    vector<int> ans;
    cout << v_b[last] - 1 << '\n';

    do {
        ans.push_back(last);
        last = v[last];
    } while (last != -1);
    reverse(ans.begin(), ans.end());

    for (auto el: ans) {
        cout << el << ' ';
    }
}