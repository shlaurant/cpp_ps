#include <bits/stdc++.h>

using namespace std;

string str;
string bomb;

bool have_bomb(string &ret) {
    return ret.size() >= bomb.size() && bomb == string(ret.end() - bomb.size(), ret.end());
}

string sol() {
    string ret;

    auto it = str.begin();
    while (it != str.end()) {
        ret += *it;
        if (have_bomb(ret)) ret.erase(ret.end() - bomb.size(), ret.end());
        ++it;
    }

    return ret.size() == 0 ? "FRULA" : ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> str >> bomb;

    cout << sol();

    return 0;
}