#include <bits/stdc++.h>

using namespace std;

const int mx = 1e5;

int n, k;

int t = 0, cnt = 0;
vector<int> visit;

void sol() {
    if (n == k) {
        cnt = 1;
        return;
    }

    visit.resize(mx + 1, INT_MAX);
    visit[n] = 1;
    queue<int> q;
    q.push(n);

    while (visit[k] == INT_MAX) {
        queue<int> temp;
        ++t;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            if (p + 1 <= mx && visit[p+1] >= t) {
                visit[p + 1] = t;
                temp.push(p + 1);
                if (p + 1 == k) ++cnt;
            }

            if (p - 1 >= 0 && visit[p-1] >= t) {
                visit[p - 1] = t;
                temp.push(p - 1);
                if (p - 1 == k) ++cnt;
            }

            if (2 * p <= mx && visit[2 * p] >= t) {
                visit[2 * p] = t;
                temp.push(2 * p);
                if (2 * p == k) ++cnt;
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