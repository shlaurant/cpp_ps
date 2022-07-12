#include <bits/stdc++.h>

using namespace std;

int t;

vector<string> dp;

const string &smin(const string &l, const string &r) {
    if (l.size() == r.size()) {
        return l >= r ? r : l;
    } else {
        return l.size() > r.size() ? r : l;
    }
}

string look_up(int val) {
    if (!dp[val].empty()) return dp[val];
    switch (val) {
        case 1:
            return "12";
        case 2:
            return "34";
        case 3:
            return "56";
        default:
            //do nothing;
            break;
    }

    string ret = look_up(1) + look_up(val - 1);
    for (auto i = 1; i < val; ++i) {
        ret = smin(ret, look_up(i) + look_up(val - i));
    }
    if (val % 2 == 0) {
        ret = smin(ret, "1" + look_up(val / 2) + "2");
    }
    if (val % 3 == 0) {
        ret = smin(ret, "3" + look_up(val / 3) + "4");
    }
    if (val % 5 == 0) {
        ret = smin(ret, "5" + look_up(val / 5) + "6");
    }

    dp[val] = ret;
    return dp[val];
}

string to_p(const string &dmap) {
    char s[dmap.size()+1];
    s[dmap.size()] = '\0';

    for (auto i = 0; i < dmap.size(); ++i) {
        switch (dmap[i]) {
            case '1':
                s[i] = '(';
                break;
            case '2':
                s[i] = ')';
                break;
            case '3':
                s[i] = '{';
                break;
            case '4':
                s[i] = '}';
                break;
            case '5':
                s[i] = '[';
                break;
            case '6':
                s[i] = ']';
                break;
        }
    }

    return string{s};
}

string sol(int val) {
    dp.resize(1001);
    return to_p(look_up(val));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    for (auto i = 0; i < t; ++i) {
        int a;
        cin >> a;
        cout << sol(a) << '\n';
    }

    return 0;
}