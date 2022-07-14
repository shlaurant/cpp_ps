#include <bits/stdc++.h>

using namespace std;

int n, k;

int t = 0, cnt = 0;

int mx = 100000;
vector<int> visit;

vector<int> np(int p) {
    vector<int> ret;
    if (p + 1 <= mx) ret.push_back(p + 1);
    if (p - 1 >= 0) ret.push_back(p - 1);
    if (2 * p <= mx) ret.push_back(2 * p);
    return ret;
}

void sol() {
    if (n == k) {
        cnt = 1;
        return;
    }
    visit.resize(mx + 1, INT_MAX);
    visit[n] = 0;
    queue<int> q;
    q.push(n);

    while (visit[k] == INT_MAX) {
        ++t;
        queue<int> temp;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            for (auto el: np(p)) {
                if (visit[el] < t) continue;
                visit[el] = t;
                if (el == k) ++cnt;
                temp.push(el);
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