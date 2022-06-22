#include <bits/stdc++.h>

using namespace std;

int main() {
    int num;
    cin >> num;

    int degrees[num + 1];
    degrees[0] = 0;
    int interval;
    cin >> interval;

    for (auto i = 1; i < num + 1; ++i) {
        cin >> degrees[i];
        degrees[i] += degrees[i - 1];
    }

    int ret = INT_MIN;

    for (auto i = 0; i + interval < num + 1; ++i) {
        ret = max(ret, degrees[i + interval] - degrees[i]);
    }

    cout << ret;
}