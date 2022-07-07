#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> input;
vector<string> ans;

void trim(string &num) {
    auto it = num.begin();
    while (*it == '0') ++it;
    num.erase(num.begin(), it);
    if (num.empty()) num = "0";
}

void find_num(const string &str) {
    auto it = find_if(str.begin(), str.end(),
                      [](char c) -> bool { return !isalpha(c); });

    while (it != str.end()) {
        auto e = find_if(it, str.end(),
                         [](char c) -> bool { return isalpha(c); });
        auto num = string(it, e);
        trim(num);
        ans.push_back(num);
        it = e;
        while (it != str.end() && isalpha(*it)) ++it;
    }
}

bool comp(const string &l, const string &r) {
    if (l.size() == r.size()) {
        for (auto i = 0; i < l.size(); ++i) {
            if (l[i] > r[i]) return false;
        }
        return true;
    } else {
        return l.size() < r.size();
    }
}

void sol() {
    for (const auto &str: input) {
        find_num(str);
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