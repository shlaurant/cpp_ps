#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> seq;

vector<bool> visit;

long long sol() {
    long long ret = 0;

    visit.resize(1e5 + 1);
    visit[seq[0]] = true;
    long long l = 0, r = 1;
    while (r < n) {
        if (visit[seq[r]]) {
            while (seq[l] != seq[r]) {
                ret += r - l;
                visit[seq[l++]] = false;
            }
            ret += r - l;
            ++r;
            ++l;
        } else {
            visit[seq[r++]] = true;
        }
    }
    ret += (r - l) * (r - l + 1) / 2;

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