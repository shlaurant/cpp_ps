#include <bits/stdc++.h>

using namespace std;

int k;
vector<int> vec;

void go(int lv, vector<vector<int>> &ans, const vector<int>::const_iterator &b,
        const vector<int>::const_iterator &e) {
    if (lv == k) return;

    ans[lv].push_back(*(b + (e - b) / 2));
    go(lv + 1, ans, b, b + (e - b) / 2);
    go(lv + 1, ans, b + (e - b) / 2 + 1, e);
}

void sol(vector<vector<int>> &ans) {
    go(0, ans, vec.begin(), vec.end());
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    int t;
    while(cin >> t) {
        vec.push_back(t);
    }

    vector<vector<int>> ans(k);
    sol(ans);
    for (const auto &r: ans) {
        for (auto i: r) {
            cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}