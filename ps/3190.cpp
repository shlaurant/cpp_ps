#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<pair<int, int>> apple;
int l;
queue<pair<int, char>> dir;

vector<vector<char>> mp;
deque<pair<int, int>> snake;

bool not_dead() {
    return mp[snake.front().first][snake.front().second] == 'S';
}

pair<int, int> dp[4]{{0,  1},
                     {1,  0},
                     {0,  -1},
                     {-1, 0}};

int check_dir(int time, int cur_dir) {
    if (time == dir.front().first) {
        auto ret =  dir.front().second == 'D' ? ++cur_dir % 4 : (cur_dir + 3) % 4;
        dir.pop();
        return ret;
    } else {
        return cur_dir;
    }
}

void move_snake(int cur_dir) {
    pair<int, int> cand = {snake.front().first + dp[cur_dir].first,
                           snake.front().second + dp[cur_dir].second};
    if (cand.first < 0 || cand.first >= n || cand.second < 0 ||
        cand.second >= n) {
        mp[snake.front().first][snake.front().second] = 'D';
    } else {
        if (mp[cand.first][cand.second] == 'S') {
            mp[snake.front().first][snake.front().second] = 'D';
            return;
        }
        snake.push_front(cand);
        if (mp[cand.first][cand.second] != 'A') {
            mp[snake.back().first][snake.back().second] = '.';
            snake.pop_back();
        }
        mp[cand.first][cand.second] = 'S';
    }
}

int sol() {
    int ret = 0;
    int cur_dir = 0;

    mp.resize(n, vector<char>(n, '.'));
    snake.push_front({0, 0});
    mp[0][0] = 'S';
    for (const auto &el: apple) {
        mp[el.first - 1][el.second - 1] = 'A';
    }

    while (not_dead()) {
        cur_dir = check_dir(ret, cur_dir);
        move_snake(cur_dir);
        ++ret;
    }
    return ret;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    apple.resize(k);
    for (auto &el: apple) {
        cin >> el.first >> el.second;
    }
    cin >> l;
    pair<int, char> t;
    for (auto i = 0; i < l; ++i) {
        cin >> t.first >> t.second;
        dir.push(t);
    }

    cout << sol();

    return 0;
}