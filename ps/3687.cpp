#include <bits/stdc++.h>

using namespace std;

string mx, mn;

vector<string> mxdp, mndp;

int cost[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

string smax(const string &l, const string &r) {
    string ll(find_if(l.begin(), l.end(),
                      [](char c) -> bool { return c != '0'; }), l.end());
    string rr(find_if(r.begin(), r.end(),
                      [](char c) -> bool { return c != '0'; }), r.end());

    if (ll.size() == rr.size()) {
        auto lit = ll.begin();
        auto rit = rr.begin();

        while (lit != ll.end()) {
            if (*lit > *rit) {
                return l;
            } else if (*lit < *rit) {
                return r;
            }
            ++lit;
            ++rit;
        }
        return l;
    } else {
        return ll.size() > rr.size() ? l : r;
    }
}

string smin(const string &l, const string &r) {
    if (l.empty()) return r;
    string ll(find_if(l.begin(), l.end(),
                      [](char c) -> bool { return c != '0'; }), l.end());
    string rr(find_if(r.begin(), r.end(),
                      [](char c) -> bool { return c != '0'; }), r.end());

    if (ll.size() == rr.size()) {
        auto lit = ll.begin();
        auto rit = rr.begin();
        while (lit != ll.end()) {
            if (*lit < *rit) {
                return l;
            } else if (*lit > *rit) {
                return r;
            }
            ++lit;
            ++rit;
        }
        return l;
    } else {
        return ll.size() > rr.size() ? r : l;
    }
}

string mx_lookup(int cnt) {
    if (cnt < 0) return "-1";
    if (cnt == 0)return "";
    if (!mxdp[cnt].empty()) return mxdp[cnt];

    string val;
    for (auto i = 0; i <= 9; ++i) {
        if (i == 0 && cnt == cost[0]) continue;
        auto t = mx_lookup(cnt - cost[i]);
        if (t != "-1") val = smax(val, t.append(to_string(i)));
    }
    if (val.empty()) val = "-1";
    mxdp[cnt] = val;
    return mxdp[cnt];
}

string mn_lookup(int cnt) {
    if (cnt < 0) return "-1";
    if (cnt == 0)return "";
    if (!mndp[cnt].empty()) return mndp[cnt];

    string val;
    for (auto i = 0; i <= 9; ++i) {
        if (i == 0 && cnt == cost[i]) continue;
        auto t = mn_lookup(cnt - cost[i]);
        if (t != "-1") val = smin(val, t.append(to_string(i)));
    }

    if (val.empty()) val = "-1";
    mndp[cnt] = val;
    return mndp[cnt];
}

void sol(int n) {
    mx = mx_lookup(n);
    mn = mn_lookup(n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    mxdp.resize(101);
    mndp.resize(101);

    int c;
    cin >> c;
    int n;
    for (auto i = 0; i < c; ++i) {
        cin >> n;
        sol(n);
        cout << mn << ' ' << mx << '\n';
    }

    return 0;
}