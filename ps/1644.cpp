#include <bits/stdc++.h>

using namespace std;

int n;
vector<bool> vec;

void filter(int i) {
    for (auto j = i; j <= n; j += i) {
        vec[j] = true;
    }
}

int next_avail(int i) {
    while (i <= n && vec[i]) {
        ++i;
    }
    return i;
}

int sol() {
    int ret = 0;

    int i = 2;
    int curSum = 0;
    queue<int> curList;

    while (i <= n) {
        curSum += i;
        curList.push(i);
        while (curSum > n) {
            curSum -= curList.front();
            curList.pop();
        }
        if (curSum == n) {
            ++ret;
        }
        filter(i);
        i = next_avail(i);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    vec.resize(n + 1);

    cout << sol();

    return 0;
}