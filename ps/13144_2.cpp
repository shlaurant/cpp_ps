//1232
#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> seq;
vector<bool> visit;

long long sol() {
    long long ret = 0;

    visit.resize(100001);
    auto s = seq.begin();
    auto e = s;
    ++e;
    visit[*s] = true;
    while (e != seq.end()) {
        if (visit[*e]) {
            while (*s != *e) {
                ret += e - s;
                visit[*s] = false;
                ++s;
            }
            ret += e - s;
            ++s;
            ++e;
        } else {
            visit[*e] = true;
            ++e;
        }
    }
    ret += (e - s) * (e - s + 1) / 2;

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    seq.resize(n);
    for (auto &el: seq) {
        cin >> el;
    }

    cout << sol();

    return 0;
}