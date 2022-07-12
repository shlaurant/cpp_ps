#include <bits/stdc++.h>

using namespace std;

string str;
string bomb;

vector<char> v;

void try_bang(vector<char>::iterator &e) {
    while (e - v.begin() >= bomb.size()) {
        if (string(e - bomb.size(), e) == bomb) {
            e -= bomb.size();
        } else {
            break;
        }
    }
}

string sol() {
    v.resize(str.size());
    auto ve = v.begin();
    auto it = str.begin();
    while (it != str.end()) {
        *ve = *it;
        ++ve;
        try_bang(ve);
        ++it;
    }

    string ret = string(v.begin(), ve);
    return ret.empty() ? "FRULA" : ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> str >> bomb;
    cout << sol();

    return 0;
}