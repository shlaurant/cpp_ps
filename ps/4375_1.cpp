#include <bits/stdc++.h>

using namespace std;

vector<int> in;
vector<int> out;

int _sol(int i) {
    int b = 1;
    int ret = 1;
    while (b % i != 0) {
        b = b * 10 + 1;
        b %= i;
        ++ret;
    }
    return ret;
}

void sol() {
    for (auto el: in) {
        out.push_back(_sol(el));
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    while (cin >> t) {
        in.push_back(t);
    }

    sol();

    for (auto el: out) {
        cout << el << '\n';
    }
}