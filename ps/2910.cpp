#include <bits/stdc++.h>

using namespace std;

int n, c, t;
map<int, int> m;

bool com(pair<int, int> a, pair<int, int> b) {
    if(a.second > b.second){
        return true;
    } else if(a.second == b.second){
        return m[a.first] < m[b.first];
    } else{
        return false;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    vector<pair<int, int>> v;

    cin >> n >> c;
    int p = 0;

    for (auto i = 0; i < n; ++i) {
        cin >> t;
        auto iter = find_if(v.begin(), v.end(),
                            [](pair<int, int> e) { return e.first == t; });
        if (iter == v.end()) {
            v.push_back({t, 1});
            m[t] = p++;
        } else {
            *iter = {t, ++iter->second};
        }
    }

    sort(v.begin(), v.end(), com);

    for (auto i = 0; i < v.size(); ++i) {
        for (auto j = 0; j < v[i].second; ++j) {
            cout << v[i].first << " ";
        }
    }

    return 0;
}