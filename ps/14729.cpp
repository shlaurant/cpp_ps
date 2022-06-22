#include <bits/stdc++.h>

using namespace std;

int n;
priority_queue<float, vector<float>, greater<>> q;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    float f;

    while (cin >> f) {
        q.push(f);
    }

    for (auto i = 0; i < 7; ++i) {
        printf("%.3f\n", q.top());
        q.pop();
    }

    return 0;
}