#include <bits/stdc++.h>

using namespace std;

int n;
string pre, suf;

string sol(string &str) {
    if(str.size() < pre.size() + suf.size()) return "NE";
    if(str.substr(0, pre.size()) == pre && str.substr(str.size() - suf.size(), str.size()) == suf){
        return "DA";
    } else return "NE";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    string str;
    cin >> str;
    pre = str.substr(0, str.find("*"));
    suf = str.substr(str.find("*") + 1, str.size());

    for (auto i = 0; i < n; ++i) {
        cin >> str;
        cout << sol(str) << '\n';
    }

    return 0;
}