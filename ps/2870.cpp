#include <bits/stdc++.h>

using namespace std;

int n;

bool isnum(char c) {
    return !isalpha(c);
}

bool is_a(char c) {
    return isalpha(c);
}

bool is_z(char c) {
    return c == '0';
}

bool is_n_z(char c) {
    return !is_z(c);
}

bool comp(const string &x, const string &y) {
    if (x.size() == y.size()) {
        return x < y;
    } else {
        return x.size() < y.size();
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> v;

    cin >> n;

    string str;
    for (auto i = 0; i < n; ++i) {
        cin >> str;
        auto b = str.begin();
        string::iterator e;
        while (b != str.end()) {
            b = find_if(b, str.end(), isnum);
            e = find_if(b, str.end(), is_a);
            if (b != str.end()) {
                v.push_back(string(b, e));
                b = e;
            }
        }
    }


    for (string &i: v) {
        if (i[0] == '0') {
            auto e = find_if(i.begin(), i.end(), is_n_z);
            if (e == i.end()) {
                i = "0";
            } else {
                i.erase(i.begin(), e);
            }
        }
    }
    sort(v.begin(), v.end(), comp);
    for (const string &i: v) {
        cout << i << '\n';
    }

    return 0;
}
