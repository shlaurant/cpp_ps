#include <bits/stdc++.h>

using namespace std;

int r, c;
vector<vector<char>> board;

vector<vector<bool>> visit;
vector<vector<int>> dp;
bool f = false;
int mx = 0;

vector<pair<int, int>> *np_of(const pair<int, int> &p) {
    auto ret = new vector<pair<int, int>>(4);
    int y, x;
    tie(y, x) = p;
    (*ret)[0] = {y - (board[y][x] - '0'), x};
    (*ret)[1] = {y, x + (board[y][x] - '0')};
    (*ret)[2] = {y + (board[y][x] - '0'), x};
    (*ret)[3] = {y, x - (board[y][x] - '0')};
    return ret;
}

bool is_out(const pair<int, int> &p) {
    return p.first < 0 || p.second < 0 || p.first >= r || p.second >= c;
}

int lookup(const pair<int, int> &p) {
    if (dp[p.first][p.second] != -1) return dp[p.first][p.second];
    if (visit[p.first][p.second]) {
        f = true;
        return 0;
    }

    visit[p.first][p.second] = true;

    auto vp = np_of(p);
    int ret = 0;
    for (const auto &el: *vp) {
        if (is_out(el) || board[el.first][el.second] == 'H') {
            ret = max(ret, 1);
            continue;
        }
        ret = max(ret, lookup(el) + 1);
    }
    delete vp;
    dp[p.first][p.second] = ret;

    visit[p.first][p.second] = false;
    return ret;
}


int sol() {
    visit.resize(r, vector<bool>(c));
    dp.resize(r, vector<int>(c, -1));

    mx = lookup({0, 0});

    return f ? -1 : mx;
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