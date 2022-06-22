#include <bits/stdc++.h>

using namespace std;

int k;
vector<char> in_vec;

long long to_i(const vector<int> &v) {
    long long ret = 0;
    long long a = 1;

    for (auto i = k; i >= 0; --i) {
        ret += v[i] * a;
        a *= 10;
    }

    return ret;
}

bool does_match(char op, int l, int r) {
    switch (op) {
        case '>':
            return l > r;
        case '<':
            return l < r;
        default:
            throw domain_error("fuck");
    }
}

void dfs(int index, vector<int> &visit, long long &imx, long long &imn) {
    if (index > k) {
        imx = max(imx, to_i(visit));
        imn = min(imn, to_i(visit));
        return;
    }

    for (auto i = 0; i < 10; ++i) {
        if (find(visit.begin(), visit.end(), i) != visit.end())
            continue;
        if (does_match(in_vec[index - 1], visit[index - 1], i)) {
            visit[index] = i;
            dfs(index + 1, visit, imx, imn);
            visit[index] = -1;
        }
    }
}

void sol(string &mx, string &mn) {
    long long imx = LONG_LONG_MIN, imn = LONG_LONG_MAX;
    vector<int> visit(10, -1);
    for (auto i = 0; i <= 9; ++i) {
        visit[0] = i;
        dfs(1, visit, imx, imn);
        visit[0] = -1;
        if (imx != INT_MIN) {
            mx = to_string(imx);
            if(mx.size() == in_vec.size()) mx = "0" + mx;
        }
        if (imn != INT_MAX) {
            mn = to_string(imn);
            if(mn.size() == in_vec.size()) mn = "0" + mn;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    for (auto i = 0; i < k; ++i) {
        char c;
        cin >> c;
        in_vec.push_back(c);
    }

    string mx, mn;
    sol(mx, mn);
    cout << mx << '\n' << mn;
}