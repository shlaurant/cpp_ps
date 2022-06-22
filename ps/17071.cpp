#include <bits/stdc++.h>

using namespace std;

void move(int x, int (&nx)[3]) {
    nx[0] = x - 1;
    nx[1] = x + 1;
    nx[2] = 2 * x;
}

int bfs(int n, int k) {
    vector<vector<bool>> vec(2, vector<bool>(500001));
    queue<pair<int, int>> q;
    q.push({n, 0});
    vec[0][n] = true;
    int turn = 0;

    while (!q.empty()) {
        if (vec[turn % 2][k]) return turn;
        int cx, t;
        tie(cx, t) = q.front();
        int nx[3];
        q.pop();
        move(cx, nx);
        if (turn == t) {
            ++turn;
            k += turn;
            if (k > 500000) return -1;
        }
        for (auto _nx: nx) {
            if (_nx < 0 || _nx > 500000) continue;
            if (!vec[turn % 2][_nx]) {
                vec[turn % 2][_nx] = true;
                q.push({_nx, turn});
            }
        }
    }
}

int sol(int n, int k) {
    return bfs(n, k);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    cout << sol(n, k);
}