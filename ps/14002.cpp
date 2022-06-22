#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;
vector<int> *rp = nullptr;
vector<vector<int>> cnt;

int sol() {
    cnt.resize(n);

    int ret = 0;

    for (auto i = 0; i < n; ++i) {
        int mx = 0;
        vector<int> *vp = nullptr;
        for (auto j = 0; j < i; ++j) {
            if (a[i] > a[j] && cnt[j].size() > mx) {
                mx = cnt[j].size();
                vp = &cnt[j];
            }
        }
        if (vp != nullptr) {
            cnt[i] = vector<int>(*vp);
        }
        cnt[i].push_back(a[i]);

        if (mx + 1 > ret) {
            ret = mx + 1;
            rp = &cnt[i];
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    a.resize(n);
    for (auto &el: a) {
        cin >> el;
    }

    cout << sol() << '\n';
    for (auto el: *rp) {
        cout << el << ' ';
    }

    return 0;
}