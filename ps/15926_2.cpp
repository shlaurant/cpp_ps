#include <bits/stdc++.h>

using namespace std;

int n;
string in;


int sol() {
    int ret = 0;
    stack<pair<char, int>> s;
    s.push({')', -1});

    for (auto i = 0; i < n; ++i) {
        if (in[i] == '(') {
            s.push({'(', i});
        } else {
            if (s.top().first == '(') {
                s.pop();
                ret = max(ret, i - s.top().second);
            } else {
                s.push({in[i], i});
            }
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> in;

    cout << sol();

    return 0;
}