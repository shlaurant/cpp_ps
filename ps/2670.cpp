#include <bits/stdc++.h>

using namespace std;

int n;
vector<double> p;

vector<vector<double>> cp;

void _make_cp(vector<double> &v) {
    auto it = v.begin();
    ++it;
    while (it != v.end()) {
        *it = *(it - 1) * *it;
        ++it;
    }
}

void make_cp() {
    auto it = p.cbegin();
    while (it != p.cend() && *it < 0.1) ++it;
    while (it != p.cend()) {
        auto e = find_if(it, p.cend(),
                         [](double d) -> bool { return d < 0.1; });
        if (e - it != 0) {
            cp.push_back(vector<double>(it, e));
            _make_cp(cp.back());
        }
        it = e;
        while (it != p.cend() && *it < 0.1) ++it;
    }
}

double max_of(const vector<double> &v) {
    double ret = 0;

    auto b = v.cbegin();
    while (b != v.cend()) {
        auto e = b;
        do {
            ++e;
            auto a = *(e - 1);
            auto aa = b == v.cbegin() ? 1 : *(b - 1);
            ret = max(ret, a / aa);
        } while (e != v.cend());
        ++b;
    }

    return ret;
}

double sol() {
    double ret = 0;

    make_cp();

    for (const auto &el: cp) {
        ret = max(ret, max_of(el));
    }

    ret *= 1000;
    ret = round(ret);

    return ret / 1000;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    p.resize(n);
    for (auto &el: p) {
        cin >> el;
    }

    printf("%.3f", sol());

    return 0;
}