#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> vec;

priority_queue<int, vector<int>, greater<>> q;

int sol() {
    sort(vec.begin(), vec.end());
    auto it = vec.begin();
    for (auto i = 0; i < n; ++i) {
        while(it != vec.end() && it->first <= i+1){
            q.push(it->second);
            ++it;
        }
        while (q.size() > i + 1) q.pop();
    }

    int ret = 0;
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
    vec.resize(n);
    for (auto &el: vec) {
        cin >> el.first >> el.second;
    }

    cout << sol();

    return 0;
}