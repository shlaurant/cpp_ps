#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<vector<bool>> v;

bool not_met(int time) {
    return !v[time % 2][k];
}

void move_n(queue<int> &q, int time) {
    queue<int> temp;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int np[] = {cur - 1, cur + 1, cur * 2};
        for (auto el: np) {
            if (el < 0 || el > 500000) continue;
            if (!v[time % 2][el]) {
                temp.push(el);
                v[time % 2][el] = true;
            }
        }
    }
    swap(temp, q);
}

void move_k(int time) {
    k += time;
}

int sol() {
    int ret = 0;

    v.resize(2, vector<bool>(500001));

    queue<int> q;
    v[0][n] = true;
    q.push(n);

    while (not_met(ret)) {
        ++ret;
        move_n(q, ret);
        move_k(ret);
        if (k > 500000) return -1;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;

    cout << sol();

    return 0;
}