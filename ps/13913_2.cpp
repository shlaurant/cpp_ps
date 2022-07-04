#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> visit;
vector<int> trace;

vector<int> ans;

int sol() {
    visit.resize(1e5 + 1);
    trace.resize(1e5 + 1);

    queue<int> q;
    q.push(n);
    visit[n] = 1;
    trace[n] = -1;

    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        if (p + 1 <= 1e5 && !visit[p + 1]) {
            visit[p + 1] = visit[p] + 1;
            q.push(p + 1);
            trace[p + 1] = p;
        }

        if (p - 1 >= 0 && !visit[p - 1]) {
            visit[p - 1] = visit[p] + 1;
            q.push(p - 1);
            trace[p - 1] = p;
        }

        if (p * 2 <= 1e5 && !visit[p * 2]) {
            visit[p * 2] = visit[p] + 1;
            q.push(p * 2);
            trace[p * 2] = p;
        }
    }
    auto cur = k;
    while (trace[cur] != -1) {
        ans.push_back(cur);
        cur = trace[cur];
    }
    ans.push_back(n);

    return visit[k] - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    cout << sol() << endl;
    auto it = ans.rbegin();
    while(it != ans.rend()){
        cout << *it << ' ';
        ++it;
    }

    return 0;
}