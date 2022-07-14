#include <bits/stdc++.h>

using namespace std;

struct shark {
    int r, c, s, d, z;
    bool dead = false;
    bool moved = false;
};

int r, c, m;

vector<shark> sv;
vector<vector<shark *>> water;

int dy[] = {0, -1, 1, 0, 0};
int dx[] = {0, 0, 0, 1, -1};

void make_water() {
    water.resize(r, vector<shark *>(c, nullptr));
    for (auto &el: sv) {
        water[el.r][el.c] = &el;
    }
}

int get_shark(int pos) {
    for (auto i = 0; i < r; ++i) {
        if (water[i][pos] != nullptr) {
            auto ret = water[i][pos]->z;
            water[i][pos]->dead = true;
            water[i][pos] = nullptr;
            return ret;
        }
    }
    return 0;
}

void _move(shark &s) {
    auto left = s.s;
    while (left > 0) {
        s.r += dy[s.d] * left;
        s.c += dx[s.d] * left;
        if (s.r < 0) {
            left = -s.r;
            s.r = 0;
            s.d = 2;
        } else if (s.r >= r) {
            left = s.r - r + 1;
            s.r = r - 1;
            s.d = 1;
        } else if (s.c < 0) {
            left = -s.c;
            s.c = 0;
            s.d = 3;
        } else if (s.c >= c) {
            left = s.c - c + 1;
            s.c = c - 1;
            s.d = 4;
        } else {
            break;
        }
    }
    return;
}

void move_shark() {
    for (auto &el: sv) {
        el.moved = false;
    }
    for (auto &el: sv) {
        if (el.dead) continue;
        if (water[el.r][el.c] == &el) water[el.r][el.c] = nullptr;
        _move(el);
        if (water[el.r][el.c] != nullptr && water[el.r][el.c]->moved) {
            if (water[el.r][el.c]->z > el.z) {
                el.dead = true;
            } else {
                water[el.r][el.c]->dead = true;
                water[el.r][el.c] = &el;
            }
        } else {
            water[el.r][el.c] = &el;
        }
        el.moved = true;
    }
}

int sol() {
    int ret = 0;
    make_water();
    int pos = -1;
    while (pos < c - 1) {
        ++pos;
        ret += get_shark(pos);
        move_shark();
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c >> m;
    sv.resize(m);
    for (auto &el: sv) {
        cin >> el.r >> el.c >> el.s >> el.d >> el.z;
        --el.r;
        --el.c;
    }

    cout << sol();

    return 0;
}