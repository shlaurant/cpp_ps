//1609
#include <bits/stdc++.h>

using namespace std;

int t, n;

vector<vector<string>> dp_mn;
vector<vector<string>> dp_mx;

int cost[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

void init_dp() {
    dp_mn.resize(101, vector<string>(2));
    dp_mx.resize(101, vector<string>(2));
}

const string &smin(const string &l, const string &r) {
    if (l.size() == r.size()) {
        return l <= r ? l : r;
    } else {
        return l.size() < r.size() ? l : r;
    }
}

const string &smax(const string &l, const string &r) {
    if (l.size() == r.size()) {
        return l >= r ? l : r;
    } else {
        return l.size() > r.size() ? l : r;
    }
}

string look_up_mn(int cnt, int low) {
    if (!dp_mn[cnt][low].empty()) return dp_mn[cnt][low];
    if (cnt == 0) return "";

    auto val = string(100, '1');

    for (auto i = low; i <= 9; ++i) {
        if (cnt - cost[i] >= 0)
            val = smin(val, to_string(i) + look_up_mn(cnt - cost[i], 0));
    }

    dp_mn[cnt][low] = val;
    return dp_mn[cnt][low];
}

string look_up_mx(int cnt, int low) {
    if (!dp_mx[cnt][low].empty()) return dp_mx[cnt][low];
    if (cnt == 0) return "";

    string val;
    for (auto i = low; i <= 9; ++i) {
        if (cnt - cost[i] >= 0)
            val = smax(val, to_string(i) + look_up_mx(cnt - cost[i], 0));
    }

    dp_mx[cnt][low] = val;
    return dp_mx[cnt][low];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    init_dp();
    for (auto i = 0; i < t; ++i) {
        cin >> n;
        cout << look_up_mn(n, 1) << ' ' << look_up_mx(n, 1) << '\n';
    }

    return 0;
}