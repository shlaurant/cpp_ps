#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<string> word;

vector<int> bit_word;
int ans = 0;

int count(int sel) {
    int ret = 0;

    for (auto bw: bit_word) {
        if ((bw & sel) == bw) ++ret;
    }

    return ret;
}

void rec(int cnt, int sel, int index) {
    if (cnt == k) {
        ans = max(ans, count(sel));
        return;
    }
    if (index >= 26) return;

    if (index != 'a' - 'a' && index != 't' - 'a' && index != 'n' - 'a' &&
        index != 'i' - 'a' && index != 'c' - 'a') {
        rec(cnt, sel, index + 1);
    }
    sel |= 1 << index;
    rec(cnt + 1, sel, index + 1);
}

int bit_of(const string &w) {
    int ret = 0;

    for (auto c: w) {
        ret |= 1 << (c - 'a');
    }

    return ret;
}

int sol() {
    for (const auto &w: word) {
        bit_word.push_back(bit_of(w));
    }

    rec(0, 0, 0);

    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> k;
    word.resize(n);
    for (auto &w: word) {
        cin >> w;
    }

    cout << sol();

    return 0;
}