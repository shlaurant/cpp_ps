#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<pair<int, int>> info;

ll sol() {
    sort(info.begin(), info.end());
    priority_queue<int, vector<int>, greater<>> pq;

    auto it = info.begin();

    int cur_date = info.front().first;
    while (it != info.end()) {
        if (it->first <= cur_date) {
            pq.push(it->second);
            ++it;
        } else {
            while(pq.size() > cur_date) pq.pop();
            cur_date = it->first;
        }
    }
    while(pq.size() > cur_date) pq.pop();

    ll ret = 0;
    while(!pq.empty()){
        ret += pq.top();
        pq.pop();
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    info.resize(n);
    for (auto &el: info) {
        cin >> el.first >> el.second;
    }

    cout << sol();

    return 0;
}