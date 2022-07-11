#include <bits/stdc++.h>

using namespace std;

int t;
vector<int> dp;

void tab(){
    dp.resize(10001, 1);
    for(auto i = 2; i <= 10001; ++i){
        dp[i] = dp[i] + dp[i-2];
    }
    for(auto i = 3; i <= 10001; ++i){
        dp[i] = dp[i] + dp[i-3];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    tab();

    for (auto i = 0; i < t; ++i) {
        int a;
        cin >> a;
        cout << dp[a] << '\n';
    }

    return 0;
}
