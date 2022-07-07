#include <bits/stdc++.h>

using namespace std;

int r, c;
vector<vector<char>> board;

int ret = 0;

void rec(int y, int x, int cnt, int track) {

}

int sol() {

    rec(0, 0, 0, 0);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c;
    board.resize(r, vector<char>(c));
    for (auto &rw: board) {
        for (auto &el: rw) {
            cin >> el;
        }
    }

    cout << sol();

    return 0;
}