#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> coins;

int sol() {

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    coins.resize(n);
    for (auto &el: coins) {
        cin >> el;
    }

    cout << sol();

    return 0;
}