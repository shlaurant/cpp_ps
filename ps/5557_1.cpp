#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<int> seq;

vector<vector<ll>> dp;

ll look_up(int index, int value) {
    if (dp[index][value] != -1) return dp[index][value];

    ll cnt = 0;

    if (index > 0) {
        if(value - seq[index] >= 0){
            cnt += look_up(index - 1, value - seq[index]);
        }
        if(value + seq[index] <= 20){
            cnt += look_up(index - 1, value + seq[index]);
        }
    } else {
        if(value == seq[index]) cnt = 1;
    }

    dp[index][value] = cnt;
    return dp[index][value];
}

ll sol() {
    dp.resize(n, vector<ll>(21, -1));
    return look_up(n - 2, seq.back());
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