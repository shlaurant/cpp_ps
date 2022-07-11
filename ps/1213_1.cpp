#include <bits/stdc++.h>

using namespace std;

vector<int> cnt;

bool not_pos() {
    int c = 0;
    for (auto el: cnt) {
        if (el % 2) {
            ++c;
            if (c > 1) return true;
        }
    }
    return false;
}

string sol() {
    if (not_pos()) return "I'm Sorry Hansoo";

    string ret;
    char m = '0';
    for (auto i = 0; i < 26; ++i) {
        if (cnt[i] % 2) {
            m = 'A' + i;
            --cnt[i];
        }
        for (auto j = 0; j < cnt[i] / 2; ++j) {
            ret += 'A' + i;
        }
    }
    auto rev = ret;
    if (m != '0') ret += m;
    reverse(rev.begin(), rev.end());
    ret += rev;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cnt.resize(26);
    char c;
    while (cin >> c) {
#ifndef ONLINE_JUDGE
        if (c == '0') break;
#endif
        ++cnt[c - 'A'];
    }

    cout << sol();

    return 0;
}