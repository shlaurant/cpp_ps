#include <bits/stdc++.h>

using namespace std;

string in, bomb;

bool have_bomb(const string &ret) {
    if (ret.size() < bomb.size()) return false;
    return ret.substr(ret.size() - bomb.size(), bomb.size()) == bomb;
}

string sol() {
    string ret;

    auto it = in.begin();
    while (it != in.end()) {
        ret += *it;
        if (have_bomb(ret)) ret.erase(ret.end() - bomb.size(), ret.end());
        ++it;
    }

    return ret.empty() ? "FRULA" : ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> in >> bomb;

    cout << sol();

    return 0;
}