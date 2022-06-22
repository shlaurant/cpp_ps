#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> p;
vector<char> ops;

int mx = INT_MIN;
int mn = INT_MAX;

int _calc(int l, int r, char op) {
    switch (op) {
        case '+':
            return l + r;
        case '-':
            return l - r;
        case '*':
            return l * r;
        case '/':
            return l / r;
        default:
            throw domain_error("???");
    }
}

int calc() {
    int ret = p[0];

    for (auto i = 0; i < ops.size(); ++i) {
        ret = _calc(ret, p[i + 1], ops[i]);
    }

    return ret;
}

void sol() {
    sort(ops.begin(), ops.end());
    do {
        auto val = calc();
        mx = max(mx, val);
        mn = min(mn, val);
    } while (next_permutation(ops.begin(), ops.end()));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    p.resize(n);
    for (auto &el: p) {
        cin >> el;
    }

    int t;
    cin >> t;
    for (auto i = 0; i < t; ++i) {
        ops.push_back('+');
    }

    cin >> t;
    for (auto i = 0; i < t; ++i) {
        ops.push_back('-');
    }

    cin >> t;
    for (auto i = 0; i < t; ++i) {
        ops.push_back('*');
    }

    cin >> t;
    for (auto i = 0; i < t; ++i) {
        ops.push_back('/');
    }

    sol();

    cout << mx << '\n' << mn;

    return 0;
}