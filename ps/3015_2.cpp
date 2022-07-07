#include <bits/stdc++.h>

using namespace std;

int n;
stack<pair<int, int>> s;

long long sol() {
    long long ret = 0;

    int h;
    cin >> h;
    s.push({h, 1});
    for (auto i = 1; i < n; ++i) {
        cin >> h;
        if (s.top().first > h) {
            s.push({h, 1});
            ++ret;
        } else if (s.top().first < h) {
            auto cnt = 1;
            while (!s.empty() && s.top().first < h) {
                ret += s.top().second;
                s.pop();
            }
            while (!s.empty() && s.top().first == h) {
                cnt += s.top().second;
                ret += s.top().second;
                s.pop();
            }
            if (!s.empty()) ++ret;
            s.push({h, cnt});
        } else {
            auto cnt = 1;
            while (!s.empty() && s.top().first == h) {
                cnt += s.top().second;
                ret += s.top().second;
                s.pop();
            }
            if (!s.empty()) ++ret;
            s.push({h, cnt});
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    cout << sol();

    return 0;
}