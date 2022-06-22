#include <bits/stdc++.h>

using namespace std;

struct Shark {
    int r, c, s, d, z;
};

typedef Shark sk;
typedef list<sk>::iterator iter;

int r, c, m;
vector<vector<iter>> mp;
list<sk> shark_i;

int catch_shark(int col) {
    for (auto &rw: mp) {
        if (rw[col] != shark_i.end()) {
            auto ret = rw[col]->z;
            shark_i.erase(rw[col]);
            rw[col] = shark_i.end();
            return ret;
        }
    }
    return 0;
}

void _move(sk &shark) {
    pair<int, int> curp = {shark.r, shark.c};
    int left = shark.s;

    while (left > 0) {
        int ny, nx;
        switch (shark.d) {
            case 1:
                ny = max(0, curp.first - left);
                left -= abs(curp.first - ny);
                curp.first = ny;
                if (ny == 0) shark.d = 2;
                break;
            case 2:
                ny = min(r - 1, curp.first + left);
                left -= abs(curp.first - ny);
                curp.first = ny;
                if (ny == r - 1) shark.d = 1;
                break;
            case 3:
                nx = min(c - 1, curp.second + left);
                left -= abs(curp.second - nx);
                curp.second = nx;
                if (nx == c - 1) shark.d = 4;
                break;
            case 4:
                nx = max(0, curp.second - left);
                left -= abs(curp.second - nx);
                curp.second = nx;
                if (nx == 0) shark.d = 3;
                break;
            default:
                throw domain_error("dfdfdf");
        }
    }

    shark.r = curp.first;
    shark.c = curp.second;
}

void move_sharks() {
    auto it = shark_i.begin();
    while (it != shark_i.end()) {
        _move(*it);
        ++it;
    }
}

void update_map() {
    for (auto &rw: mp) {
        fill(rw.begin(), rw.end(), shark_i.end());
    }
    auto it = shark_i.begin();
    while (it != shark_i.end()) {
        if (mp[it->r][it->c] == shark_i.end()) {
            mp[it->r][it->c] = it;
            ++it;
        } else {
            if (mp[it->r][it->c]->z > it->z) {
                auto t = ++it;
                shark_i.erase(--it);
                it = t;
            } else {
                shark_i.erase(mp[it->r][it->c]);
                mp[it->r][it->c] = it;
                ++it;
            }
        }
    }
}

int sol() {
    int ret = 0;
    int fisher = -1;
    while (fisher < c - 1) {
        ++fisher;
        ret += catch_shark(fisher);
        move_sharks();
        update_map();
    }

    return ret;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c >> m;
    mp.resize(r, vector<iter>(c, shark_i.end()));

    for (auto i = 0; i < m; ++i) {
        int sr, sc, s, d, z;
        cin >> sr >> sc >> s >> d >> z;
        sk sk1;
        sk1.r = sr - 1;
        sk1.c = sc - 1;
        sk1.s = s;
        sk1.d = d;
        sk1.z = z;
        shark_i.push_back(sk1);
        mp[sk1.r][sk1.c] = --shark_i.end();
    }

    cout << sol();

    return 0;
}