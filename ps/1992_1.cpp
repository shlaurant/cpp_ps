//1535
#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<char>> input;

bool is_mono(const pair<int, int> &s, const pair<int, int> &e) {
    char first = input[s.first][s.second];
    for (auto y = s.first; y < e.first; ++y) {
        for (auto x = s.second; x < e.second; ++x) {
            if(input[y][x] != first) return false;
        }
    }
    return true;
}
string sol(const pair<int, int> &s, const pair<int, int> &e) {
    if (is_mono(s, e)) {
        return string(1, input[s.first][s.second]);
    } else {
        string ret = "(";
        ret.append(
                sol(s, {(s.first + e.first) / 2, (s.second + e.second) / 2}));
        ret.append(sol({s.first, (s.second + e.second) / 2},
                       {(s.first + e.first) / 2, e.second}));
        ret.append(sol({(s.first + e.first) / 2, s.second},
                       {e.first, (s.second + e.second) / 2}));
        ret.append(
                sol({(s.first + e.first) / 2, (s.second + e.second) / 2}, e));
        ret.append(")");
        return ret;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    input.resize(n, vector<char>(n));
    for (auto &rw: input) {
        for (auto &el: rw) {
            cin >> el;
        }
    }

    cout << sol({0, 0}, {n, n});

    return 0;
}