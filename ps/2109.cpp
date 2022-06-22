#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> in;

int sol() {
    if (n == 0) return 0;

    int ret = 0;
    priority_queue<int, vector<int>, greater<>> q;
    sort(in.begin(), in.end());

    for (auto i = 0; i < n; ++i) {
        q.push(in[i].second);
        if (q.size() > in[i].first) q.pop();
    }
    while (!q.empty()) {
        ret += q.top();
        q.pop();
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    in.resize(n);
    for (auto &el: in) {
        cin >> el.second >> el.first;
    }

    cout << sol();

    return 0;
}