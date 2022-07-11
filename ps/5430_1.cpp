#include <bits/stdc++.h>

using namespace std;

int t;
string p;
deque<int> arr;

string sol() {
    bool is_r = false;

    for (auto el: p) {
        if (el == 'R') {
            is_r = !is_r;
        } else {
            if (arr.empty()) {
                return "error";
            } else if (is_r) {
                arr.pop_back();
            } else {
                arr.pop_front();
            }
        }
    }

    string ret = "[";
    if (is_r) reverse(arr.begin(), arr.end());
    for (auto el: arr) {
        ret += to_string(el);
        ret += ',';
    }
    if (!arr.empty()) ret.erase(--ret.end());
    ret += ']';
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    for (auto i = 0; i < t; ++i) {
        cin >> p;
        int n;
        cin >> n;
        arr.resize(n);
        char c;
        cin >> c;
        for (auto &el: arr) {
            cin >> el;
            cin >> c;
        }
        if (n == 0) cin >> c;
        cout << sol() << '\n';
    }

    return 0;
}