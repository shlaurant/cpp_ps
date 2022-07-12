//1512
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> ing;

int sol() {
    sort(ing.begin(), ing.end());
    int ret = 0;
    int l = 0, r = n - 1;
    while (l < r) {
        if (ing[l] + ing[r] == m) {
            ++ret;
            ++l;
            --r;
        } else if (ing[l] + ing[r] > m) {
            --r;
        } else {
            ++l;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    ing.resize(n);
    for (auto &el: ing) {
        cin >> el;
    }

    cout << sol();

    return 0;
}