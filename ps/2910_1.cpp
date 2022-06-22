#include <bits/stdc++.h>

using namespace std;

int n, c;
vector<int> in;

vector<pair<int, int>> _ans;
map<int, int> cnt;

bool fre_comp(const pair<int, int> &l, const pair<int, int> &r) {
    if (cnt[l.first] < cnt[r.first]) return false;
    if (cnt[l.first] == cnt[r.first]) return l.second < r.second;
    return true;
}

void sol() {
    int order = 0;
    for (auto el: in) {
        ++cnt[el];
        if (cnt[el] == 1){
            _ans.push_back({el, order});
            ++order;
        }
    }
    sort(_ans.begin(), _ans.end(), fre_comp);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> c;
    in.resize(n);

    for (auto &el: in) {
        cin >> el;
    }

    sol();

    for (auto el: _ans) {
        for (auto i = 0; i < cnt[el.first]; ++i) {
            cout << el.first << ' ';
        }
    }

    return 0;
}