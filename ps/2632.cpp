#include <bits/stdc++.h>

using namespace std;

int sz, m, n;
list<int> a, b;
int suma = 0, sumb = 0;

int calc(int size, const list<int> &pizza, int s) {
    if (size == 0) return 1;
    if (size == s) return 1;

    int ret = 0;

    auto b = pizza.begin();
    auto e = ++pizza.begin();
    int sum = *b;
    while (b != pizza.end()) {
        if (sum == size) {
            ++ret;
            sum -= *b;
            ++b;
            sum += *e;
            ++e;
            if (e == pizza.end()) e = pizza.begin();
        } else if (sum > size) {
            sum -= *b;
            ++b;
        } else if (sum < size) {
            sum += *e;
            ++e;
            if (e == pizza.end()) e = pizza.begin();
        }
    }

    return ret;
}

long long sol() {
    long long ret = 0;

    for (auto i = 0; i <= min(suma, sz); ++i) {
        auto q = calc(i, a, suma);
        if (q != 0 && sz - i <= sumb) {
            auto p = calc(sz - i, b, sumb);
            ret += q * p;
        }
    }

    return ret;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> sz;
    cin >> m >> n;
    for (auto i = 0; i < m; ++i) {
        int t;
        cin >> t;
        suma += t;
        a.push_back(t);
    }

    for (auto i = 0; i < n; ++i) {
        int t;
        cin >> t;
        sumb += t;
        b.push_back(t);
    }

    cout << sol();

    return 0;
}