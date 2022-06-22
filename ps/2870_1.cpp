#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> in;

vector<string> ans;

bool is_num(char c) {
    return c >= '0' && c <= '9';
}

bool is_not_0(char c) {
    return c > '0' && c <= '9';
}

bool _ia(char c) {
    return isalpha(c);
}

string trim(const string &str) {
    string::const_iterator b;
    b = find_if(str.begin(), --str.end(), is_not_0);
    return string(b, str.end());
}


void find_num(const string &str) {
    string::const_iterator b, e;
    b = str.begin();
    while ((b = find_if(b, str.end(), is_num)) != str.end()) {
        e = find_if(b, str.end(), _ia);
        ans.push_back(trim(string(b, e)));
        b = e;
    }
}

bool comp(const string &l, const string &r) {
    if (l.size() < r.size()) return true;
    if (l.size() > r.size()) return false;
    return l <= r;
}

void sol() {
    for (const auto &str: in) {
        find_num(str);
    }

    sort(ans.begin(), ans.end(), comp);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    in.resize(n);

    for (auto &str: in) {
        cin >> str;
    }

    sol();

    for (const auto &i: ans) {
        cout << i << '\n';
    }
}