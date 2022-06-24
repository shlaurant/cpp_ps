#include <bits/stdc++.h>

using namespace std;

int sol(int n, vector<bool> &sifter) {
    int ret = 0;
    auto dq = new deque<int>;
    int sum = 0;

    for (auto i = 2; i <= n; ++i) {
        if (sifter[i]) continue;
        sifter[i] = true;
        auto j = 2 * i;
        while (j <= n) {
            sifter[j] = true;
            j += i;
        }
        sum += i;
        dq->push_back(i);
        while (sum > n) {
            sum -= dq->front();
            dq->pop_front();
        }
        if (sum == n) ++ret;
    }
    delete dq;

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    auto sifter = new vector<bool>(n + 1);

    cout << sol(n, *sifter);
    delete sifter;

    return 0;
}