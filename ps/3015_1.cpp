#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> p;

long long sol() {
    long long ret = 0;
    stack<pair<int, int>> s;

    for (auto el: p) {
        if (s.empty()) {
            s.push({el, 1});
            continue;
        }
        int cnt = 1;
        while (el >= s.top().first) {
            if (el == s.top().first) cnt += s.top().second;
            ret += s.top().second;
            s.pop();
            if (s.empty()) break;
        }
        if (!s.empty()) ++ret;
        s.push({el, cnt});
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    p.resize(n);
    for (auto &el: p) {
        cin >> el;
    }

    cout << sol();

    return 0;
}