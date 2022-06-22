#include <bits/stdc++.h>

using namespace std;

int x;

int sol() {
    vector<int> sticks;
    sticks.push_back(64);

    while (accumulate(sticks.begin(), sticks.end(), 0) != x) {
        sticks[sticks.size() - 1] /= 2;
        int sum = accumulate(sticks.begin(), sticks.end(), 0);
        if(sum < x) sticks.push_back(sticks[sticks.size() - 1]);
    }

    return sticks.size();
}

int main() {
    cin >> x;

    cout << sol();
}