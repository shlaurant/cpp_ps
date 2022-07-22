#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> offers;

int sum(priority_queue<int, vector<int>, greater<>> &pq){
    int ret = 0;

    while(!pq.empty()){
        ret += pq.top();
        pq.pop();
    }

    return ret;
}

int sol() {
    sort(offers.begin(), offers.end());
    priority_queue<int, vector<int>, greater<>> pq;

    int index = 0;
    int day = offers[0].first;
    while (index < offers.size()) {
        if (offers[index].first <= day) {
            pq.push(offers[index].second);
            ++index;
        } else {
            while (pq.size() > day) pq.pop();
            day = offers[index].first;
        }
    }
    while (pq.size() > day) pq.pop();

    return sum(pq);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    offers.resize(n);
    for (auto &el: offers) {
        cin >> el.second >> el.first;
    }

    cout << sol();

    return 0;
}