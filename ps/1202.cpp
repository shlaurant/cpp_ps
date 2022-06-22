#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<pair<int, int>> jams;
vector<int> bags;

long long sol() {
    long long ret = 0;

    sort(bags.begin(), bags.end());
    sort(jams.begin(), jams.end());

    auto bit = bags.begin();
    auto jit = jams.begin();
    priority_queue<int> q;

    while (bit != bags.end() && jit != jams.end()) {
        if (*bit >= jit->first) {
            q.push(jit->second);
            jit++;
        } else {
            if (!q.empty()) {
                ret += q.top();
                q.pop();
            }
            ++bit;
        }
    }

    while (bit != bags.end() && !q.empty()) {
        ret += q.top();
        q.pop();
        ++bit;
    }

    return ret;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;

    jams.resize(n);
    bags.resize(k);

    for (auto &el: jams) {
        int a, b;
        cin >> a >> b;
        el = {a, b};
    }

    for (auto &el: bags) {
        cin >> el;
    }

    cout << sol();

    return 0;
}