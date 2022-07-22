#include <bits/stdc++.h>

using namespace std;

const int mx = 100000;

int n, k;
int t = 0, cnt = 0;

vector<int> visit;

vector<int> np(int p) {
    auto ret = vector<int>(3);

    ret[0] = p + 1;
    ret[1] = p - 1;
    ret[2] = 2 * p;

    return ret;
}

void sol() {
    if (n == k) {
        cnt = 1;
        return;
    }

    visit.resize(mx + 1, mx + 1);
    queue<int> q;
    visit[n] = 0;
    q.push(n);
    while (visit[k] == mx + 1) {
        queue<int> temp;
        ++t;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            for (auto el: np(p)) {
                if (el < 0 || el > mx) continue;
                if (visit[el] < t) continue;
                visit[el] = t;
                temp.push(el);
                if (el == k) ++cnt;
            }
        }
        swap(temp, q);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    sol();
    cout << t << '\n' << cnt;

    return 0;
}