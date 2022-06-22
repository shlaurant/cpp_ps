#include <bits/stdc++.h>

using namespace std;

int t;
vector<int> in;
vector<int> ans;

void sol() {
    for (auto el: in) {
        long long k = 5;
        int ret = 0;
        while (el >= k) {
            ret += el / k;
            k *= 5;
        }
        ans.push_back(ret);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    in.resize(t);
    for (auto &el: in) {
        cin >> el;
    }

    sol();

    for (auto el: ans) {
        cout << el << '\n';
    }
}