#include <bits/stdc++.h>

using namespace std;

struct piece {
    int r, c, d;
};

int n, k;
vector<vector<pair<int, vector<piece *>>>> board;

vector<piece *> pv;

int dy[] = {0, 0, 0, -1, 1};
int dx[] = {0, 1, -1, 0, 0};

void move_white(piece *p, int ny, int nx) {
    int y = p->r, x = p->c;
    auto b = find(board[y][x].second.begin(), board[y][x].second.end(), p);
    copy(b, board[y][x].second.end(), back_inserter(board[ny][nx].second));
    auto it = b;
    while (it != board[y][x].second.end()) {
        (**it).r = ny;
        (**it).c = nx;
        ++it;
    }
    board[y][x].second.erase(b, board[y][x].second.end());
}

void move_red(piece *p, int ny, int nx) {
    int y = p->r, x = p->c;
    auto b = find(board[y][x].second.begin(), board[y][x].second.end(), p);
    copy(b, board[y][x].second.end(), back_inserter(board[ny][nx].second));
    auto it = b;
    while (it != board[y][x].second.end()) {
        (**it).r = ny;
        (**it).c = nx;
        ++it;
    }
    board[y][x].second.erase(b, board[y][x].second.end());

    b = find(board[ny][nx].second.begin(), board[ny][nx].second.end(), p);
    reverse(b, board[ny][nx].second.end());
}

void move_blue(piece *p, int ny, int nx) {
    int y = p->r, x = p->c;
    auto b = find(board[y][x].second.begin(), board[y][x].second.end(), p);
    switch ((*b)->d) {
        case 1:
            (*b)->d = 2;
            break;
        case 2:
            (*b)->d = 1;
            break;
        case 3:
            (*b)->d = 4;
            break;
        case 4:
            (*b)->d = 3;
            break;
    }
    ny = y + dy[(*p).d];
    nx = x + dx[(*p).d];

    switch (board[ny][nx].first) {
        case 0:
            move_white(p, ny, nx);
            break;
        case 1:
            move_red(p, ny, nx);
            break;
        case 2:
            //do nothing
            break;
    }
}

void move_p(piece *p) {
    int ny = p->r + dy[p->d];
    int nx = p->c + dx[p->d];
    switch (board[ny][nx].first) {
        case 0:
            move_white(p, ny, nx);
            break;
        case 1:
            move_red(p, ny, nx);
            break;
        case 2:
            move_blue(p, ny, nx);
            break;
    }
}

bool is_over(const piece *const p) {
    return board[p->r][p->c].second.size() >= 4;
}

int sol() {
    int ret = 0;

    while (ret < 1000) {
        ret++;
        for (auto el: pv) {
            move_p(el);
            if (is_over(el)) return ret;
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    board.resize(n + 2, vector<pair<int, vector<piece *>>>(n + 2, {2,
                                                                   vector<piece *>()}));
    for (auto y = 1; y <= n; ++y) {
        for (auto x = 1; x <= n; ++x) {
            cin >> board[y][x].first;
        }
    }

    for (auto i = 0; i < k; ++i) {
        auto pp = new piece();
        cin >> pp->r >> pp->c >> pp->d;
        board[pp->r][pp->c].second.push_back(pp);
        pv.push_back(pp);
    }

    cout << sol();

    return 0;
}