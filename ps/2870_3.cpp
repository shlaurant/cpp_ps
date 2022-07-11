#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> input;

vector<string> ans;

bool is_num(char c) {
    return !isalpha(c);
}

bool is_alpha(char c) {
    return isalpha(c);
}

string &trim(string &str) {
    while (str.size() > 1) {
        if (str[0] == '0') str.erase(0, 1);
        else break;
    }
    return str;
}

void find_num(const string &str) {
    auto b = find_if(str.begin(), str.end(), is_num);
    while (b != str.end()) {
        auto e = find_if(b, str.end(), is_alpha);
        string num = string(b, e);
        ans.push_back(trim(num));
        b = find_if(e, str.end(), is_num);
    }
}

bool comp(const string &l, const string &r) {
    if (l.size() == r.size()) {
        return l <= r;
    } else {
        return l.size() < r.size();
    }
}

void sol() {
    for (const auto &el: input) {
        find_num(el);
    }
    sort(ans.begin(), ans.end(), comp);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    input.resize(n);
    for (auto &el: input) {
        cin >> el;
    }

    sol();

    for (const auto &el: ans) {
        cout << el << '\n';
    }

    return 0;
}