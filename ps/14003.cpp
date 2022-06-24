#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> p;
vector<int> lis;


stack<int> s;

void sol() {
    lis.resize(n);
    auto e = lis.begin();
    auto it = p.begin();
    while (it != p.end()) {
        auto lb = lower_bound(lis.begin(), e, it->first);
        if (lb == e) ++e;
        *lb = it->first;
        it->second = (lb - lis.begin());
        ++it;
    }

    int pos = e - lis.begin() - 1;
    for (auto i = n - 1; i >= 0; --i) {
        if (p[i].second == pos) {
            --pos;
            s.push(p[i].first);
        }
        if (pos < 0) break;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    p.resize(n);
    for (auto &el: p) {
        cin >> el.first;
    }

    sol();

    cout << s.size() << '\n';
    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }

    return 0;
}