#include <bits/stdc++.h>

using namespace std;

int n, l;
vector<pair<int, int>> ponds;

int sol() {
    int ret = 0;

    sort(ponds.begin(), ponds.end());
    auto p = 0;
    for (const auto &el: ponds) {
        if(el.first > p){
            p = el.first;
        }
        while(p < el.second){
            p += l;
            ++ret;
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> l;
    ponds.resize(n);
    for (auto &el: ponds) {
        cin >> el.first >> el.second;
    }

    cout << sol();

    return 0;
}