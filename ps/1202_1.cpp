#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<pair<int, int>> jams;
vector<int> bags;

long long sol() {
    long long ret = 0;

    sort(bags.begin(), bags.end());
    sort(jams.begin(), jams.end());

    priority_queue<int> q;

    auto bit = bags.begin();
    auto jit = jams.begin();

    while (bit != bags.end() && jit != jams.end()) {
        while (*bit >= jit->first && jit != jams.end()) {
            q.push(jit->second);
            ++jit;
        }
        if (!q.empty()) {
            ret += q.top();
            q.pop();
        }
        ++bit;
    }

    while (bit != bags.end()) {
        if(q.empty()) break;
        ret += q.top();
        q.pop();
        ++bit;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    jams.resize(n);
    bags.resize(k);

    for (auto &el: jams) {
        cin >> el.first >> el.second;
    }

    for (auto &el: bags) {
        cin >> el;
    }

    cout << sol();

    return 0;
}