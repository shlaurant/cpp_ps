#include <bits/stdc++.h>

using namespace std;

struct dc {
    int x, y, d, g;
    vector<int> cv;
};

int n;
vector<dc> curves;

vector<vector<bool>> mp;

void make_cv(dc &dc) {
    dc.cv.push_back(dc.d);
    for (auto i = 0; i < dc.g; ++i) {
        vector<int> temp;
        auto cnt = dc.cv.size();
        for (auto j = 0; j < cnt; ++j) {
            temp.push_back((dc.cv[j] + 3) % 4);
        }
        reverse(temp.begin(), temp.end());
        for(auto el:temp){
            dc.cv.push_back((el + 2)%4);
        }
    }
}

void draw(const dc &dc) {
    pair<int, int> cp = {dc.y, dc.x};
    mp[cp.first][cp.second] = true;
    for (auto el: dc.cv) {
        switch (el) {
            case 0:
                cp = {cp.first, cp.second + 1};
                break;
            case 1:
                cp = {cp.first - 1, cp.second};
                break;
            case 2:
                cp = {cp.first, cp.second - 1};
                break;
            case 3:
                cp = {cp.first + 1, cp.second};
                break;
        }
        mp[cp.first][cp.second] = true;
    }
}

int cnt() {
    int ret = 0;
    for (auto y = 0; y < 100; ++y) {
        for (auto x = 0; x < 100; ++x) {
            if(mp[y][x] && mp[y + 1][x] && mp[y][x + 1] && mp[y+1][x+1]) ++ret;
        }
    }
    return ret;
}

int sol() {
    mp.resize(101, vector<bool>(101));

    for (auto &el: curves) {
        make_cv(el);
        draw(el);
    }
    return cnt();
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    curves.resize(n);
    for (auto &el: curves) {
        cin >> el.x >> el.y >> el.d >> el.g;
    }

    cout << sol();

    return 0;
}