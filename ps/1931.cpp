#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> in;

bool comp(const pair<int, int> &l, const pair<int, int> &r) {
    if (l.second != r.second) {
        return l.second < r.second;
    } else {
        return l.first <= r.first;
    }
}

int sol() {
    sort(in.begin(), in.end(), comp);
    auto it = in.begin();
    auto last = it;
    int ret = 1;
    ++it;

    while (it != in.end()) {
        if (it->first >= last->second) {
            last = it;
            ++ret;
        }
        ++it;
    }

    return ret;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    in.resize(n);
    for (auto &el: in) {
        int a, b;
        cin >> a >> b;
        el = {a, b};
    }

    cout << sol();

    return 0;
}