#include <bits/stdc++.h>

using namespace std;

int r, c;

vector<vector<int>> room;
deque<pair<int, int>> cams;
vector<vector<int>> v;

int ret = INT_MAX;

int cnt() {
    int ret = 0;

    for (auto y = 0; y < r; ++y) {
        for (auto x = 0; x < c; ++x) {
            if (room[y][x] == 0 && v[y][x] == 0) ++ret;
        }
    }

    return ret;
}

void paint1(const pair<int, int> &cam, int dir, int val) {
    switch (dir) {
        case 0:
            for (auto x = cam.second + 1; x < c; ++x) {
                if(room[cam.first][x] == 6) break;
                v[cam.first][x] += val;
            }
            break;
        case 1:
            for (auto y = cam.first - 1; y >= 0; --y) {
                if(room[y][cam.second] == 6) break;
                v[y][cam.second] += val;
            }
            break;
        case 2:
            for (auto x = cam.second - 1; x >= 0; --x) {
                if(room[cam.first][x] == 6) break;
                v[cam.first][x] += val;
            }
            break;
        case 3:
            for (auto y = cam.first + 1; y < r; ++y) {
                if(room[y][cam.second] == 6) break;
                v[y][cam.second] += val;
            }
            break;
    }
}

void paint2(const pair<int, int> &cam, int dir, int val) {
    switch (dir) {
        case 0:
            paint1(cam, 0, val);
            paint1(cam, 2, val);
            break;
        case 1:
            paint1(cam, 1, val);
            paint1(cam, 3, val);
            break;
        case 2:
            paint2(cam, 0, val);
            break;
        case 3:
            paint2(cam, 1, val);
            break;
    }
}

void paint3(const pair<int, int> &cam, int dir, int val) {
    switch (dir) {
        case 0:
            paint1(cam, 0, val);
            paint1(cam, 1, val);
            break;
        case 1:
            paint1(cam, 1, val);
            paint1(cam, 2, val);
            break;
        case 2:
            paint1(cam, 2, val);
            paint1(cam, 3, val);
            break;
        case 3:
            paint1(cam, 3, val);
            paint1(cam, 0, val);
            break;
    }
}

void paint5(const pair<int, int> &cam, int dir, int val) {
    paint2(cam, 0, val);
    paint2(cam, 1, val);
}

void paint4(const pair<int, int> &cam, int dir, int val) {
    paint5(cam, dir, val);
    switch (dir) {
        case 0:
            paint1(cam, 3, -val);
            break;
        case 1:
            paint1(cam, 0, -val);
            break;
        case 2:
            paint1(cam, 1, -val);
            break;
        case 3:
            paint1(cam, 2, -val);
            break;
    }
}

void paint(const pair<int, int> &cam, int dir, int val) {
    switch (room[cam.first][cam.second]) {
        case 1:
            paint1(cam, dir, val);
            break;
        case 2:
            paint2(cam, dir, val);
            break;
        case 3:
            paint3(cam, dir, val);
            break;
        case 4:
            paint4(cam, dir, val);
            break;
        case 5:
            paint5(cam, dir, val);
            break;
    }
}

void dfs() {
    if (cams.size() == 0) {
        ret = min(ret, cnt());
        return;
    }

    auto cam = cams.front();
    cams.pop_front();

    for (auto i = 0; i < 4; ++i) {
        paint(cam, i, 1);
        dfs();
        paint(cam, i, -1);
    }

    cams.push_front(cam);
}

int sol() {
    v.resize(r, vector<int>(c));
    dfs();
    return ret;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c;
    room.resize(r, vector<int>(c));
    for (auto i = 0; i < r; ++i) {
        for (auto j = 0; j < c; ++j) {
            cin >> room[i][j];
            if (room[i][j] != 0 && room[i][j] != 6) cams.push_back({i, j});
        }
    }

    cout << sol();

    return 0;
}