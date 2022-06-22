#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> h;

long long sol() {
    long long ret = 0;

    stack<pair<int, int>> s;
    for (auto i = 0; i < n; ++i) {
        if (s.empty()) {
            s.push({i, 0});
        } else {
            ++ret;
            int cnt = 0;
            while (h[s.top().first] <= h[i]) {
                if (h[s.top().first] == h[i]) cnt = s.top().second + 1;
                ret += s.top().second;
                s.pop();
                if (!s.empty()) ++ret;
                else break;
            }
            s.push({i, cnt});
        }
    }

    return ret;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    h.resize(n);
    for (auto &el: h) {
        cin >> el;
    }

    cout << sol();

    return 0;
}