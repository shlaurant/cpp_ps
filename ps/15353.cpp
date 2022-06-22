#include <bits/stdc++.h>

using namespace std;

vector<int> a;
vector<int> b;

vector<int> ans;

typedef vector<int>::const_reverse_iterator iter;

void sol() {
    ans.resize(max(a.size(), b.size()) + 1);
    iter ia = a.rbegin(), ib = b.rbegin();
    auto ians = ans.rbegin();

    int up = 0;
    while (ians != ans.rend()) {
        int av = 0, bv = 0;

        if (ia != a.rend()) av = *ia;
        if (ib != b.rend()) bv = *ib;
        *ians = (av + bv + up) % 10;
        up = (av + bv + up) / 10;
        if (ia != a.rend()) ++ia;
        if (ib != b.rend()) ++ib;
        ++ians;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    char c;
    while (cin.get(c) && !isspace(c)) {
        a.push_back(c - '0');
    }
    while (cin.get(c) && isalnum(c)) {
        b.push_back(c - '0');
    }

    sol();
    auto it = ans.begin();
    while (*it == 0) {
        ++it;
    }
    while (it != ans.end()) {
        cout << *it;
        ++it;
    }
}