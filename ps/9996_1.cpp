#include <bits/stdc++.h>

using namespace std;

int n;
string pattern;

string pre;
string suf;

void split() {
    auto it = find(pattern.begin(), pattern.end(), '*');
    pre = string(pattern.begin(), it);
    suf = string(++it, pattern.end());
}

bool sol(string &str) {
    if (str.size() < pre.size() + suf.size()) return false;
    return string(str.begin(), str.begin() + pre.size()) == pre &&
           string(str.end() - suf.size(), str.end()) == suf;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> pattern;

    split();

    string tc;
    for (auto i = 0; i < n; ++i) {
        cin >> tc;
        sol(tc) ? cout << "DA\n" : cout << "NE\n";
    }

    return 0;
}