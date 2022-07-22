#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct node {
    int time, id, cuid;

    bool operator<(const node &rhs) const {
        if (time == rhs.time) {
            return id < rhs.id;
        } else return time < rhs.time;
    }

    bool operator>(const node &rhs) const {
        return !(*this < rhs);
    }
};

int n, k;
vector<pair<int, int>> line;

priority_queue<node, vector<node>, greater<>> pq;
vector<int> result;

ll sol();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    line.resize(n);
    for (auto &el: line) {
        cin >> el.first >> el.second;
    }

    cout << sol();

    return 0;
}

ll sol() {
    stack<pair<int, int>> s;

    for (const auto &el: line) {
        int cuid, cnt;
        tie(cuid, cnt) = el;
        if (pq.size() < k) {
            int id = pq.size();
            pq.push({el.second, id, el.first});
        } else {
            auto p = pq.top();
            pq.pop();
            pq.push({p.time + el.second, p.id, el.first});
            if (s.empty()) {
                s.push({p.time, p.cuid});
            } else {
                if (s.top().first == p.time) s.push({p.time, p.cuid});
                else {
                    while (!s.empty()) {
                        result.push_back(s.top().second);
                        s.pop();
                    }
                    s.push({p.time, p.cuid});
                }
            }
        }
    }

    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        if (s.empty()) {
            s.push({p.time, p.cuid});
        } else {
            if (s.top().first == p.time) s.push({p.time, p.cuid});
            else {
                while (!s.empty()) {
                    result.push_back(s.top().second);
                    s.pop();
                }
                s.push({p.time, p.cuid});
            }
        }
    }

    while (!s.empty()) {
        result.push_back(s.top().second);
        s.pop();
    }

    ll ret = 0;

    for (ll i = 1; i <= n; ++i) {
        ret += i * result[i - 1];
    }

    return ret;
}