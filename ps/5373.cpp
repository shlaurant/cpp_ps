#include <bits/stdc++.h>

using namespace std;

struct block {
    int z, y, x;
    vector<tuple<int, int, int>> color = {{0, 1, 1},
                                          {2, 1, 1},
                                          {1, 2, 1},
                                          {1, 0, 1},
                                          {1, 1, 0},
                                          {1, 1, 2}};
};

vector<block> cube;

void rot_cw(int &a, int &b) {
    int ta = b;
    int tb = 3 - a - 1;
    a = ta;
    b = tb;
}

void rot_ccw(int &a, int &b) {
    int ta = 3 - b - 1;
    int tb = a;
    a = ta;
    b = tb;
}

void init_cube() {
    cube.clear();
    for (auto z = 0; z < 3; ++z) {
        for (auto y = 0; y < 3; ++y) {
            for (auto x = 0; x < 3; ++x) {
                cube.push_back({z, y, x});
            }
        }
    }
}

void rz_cw(int z) {
    auto it = cube.begin();
    while (it != cube.end()) {
        if (it->z == z) {
            rot_cw(it->y, it->x);
            for (auto &el: it->color) {
                rot_cw(get<1>(el), get<2>(el));
            }
        }
        ++it;
    }
}

void rz_ccw(int z) {
    auto it = cube.begin();
    while (it != cube.end()) {
        if (it->z == z) {
            rot_ccw(it->y, it->x);
            for (auto &el: it->color) {
                rot_ccw(get<1>(el), get<2>(el));
            }
        }
        ++it;
    }
}

void ry_cw(int y) {
    auto it = cube.begin();
    while (it != cube.end()) {
        if (it->y == y) {
            rot_cw(it->z, it->x);
            for (auto &el: it->color) {
                rot_cw(get<0>(el), get<2>(el));
            }
        }
        ++it;
    }
}

void ry_ccw(int y) {
    auto it = cube.begin();
    while (it != cube.end()) {
        if (it->y == y) {
            rot_ccw(it->z, it->x);
            for (auto &el: it->color) {
                rot_ccw(get<0>(el), get<2>(el));
            }
        }
        ++it;
    }
}

void rx_cw(int x) {
    auto it = cube.begin();
    while (it != cube.end()) {
        if (it->x == x) {
            rot_cw(it->z, it->y);
            for (auto &el: it->color) {
                rot_cw(get<0>(el), get<1>(el));
            }
        }
        ++it;
    }
}

void rx_ccw(int x) {
    auto it = cube.begin();
    while (it != cube.end()) {
        if (it->x == x) {
            rot_ccw(it->z, it->y);
            for (auto &el: it->color) {
                rot_ccw(get<0>(el), get<1>(el));
            }
        }
        ++it;
    }
}

char up_of(const block &b) {
    char arr[] = {'w', 'y', 'r', 'o', 'g', 'b'};
    auto it = find_if(b.color.begin(), b.color.end(),
                      [](tuple<int, int, int> t) -> bool {
                          return get<0>(t) == 0;
                      });
    return arr[it - b.color.begin()];
}

string print_up() {
    vector<vector<char>> up(3, vector<char>(3));
    for (const auto &el: cube) {
        if (el.z == 0) {
            up[el.y][el.x] = up_of(el);
        }
    }
    string ret;
    for (auto &rw: up) {
        for (auto el: rw) {
            cout << el;
        }
        cout << '\n';
    }
    return ret;
}

string sol(const vector<string> &cmd) {
    init_cube();

    for (const auto &el: cmd) {
        switch (el[0]) {
            case 'U':
                if (el[1] == '+') rz_cw(0);
                else rz_ccw(0);
                break;
            case 'D':
                if (el[1] == '+') rz_ccw(2);
                else rz_cw(2);
                break;
            case 'F':
                if (el[1] == '+') ry_cw(2);
                else ry_ccw(2);
                break;
            case 'B':
                if (el[1] == '+') ry_ccw(0);
                else ry_cw(0);
                break;
            case 'L':
                if (el[1] == '+') rx_cw(0);
                else rx_ccw(0);
                break;
            case 'R':
                if (el[1] == '+') rx_ccw(2);
                else rx_cw(2);
                break;
        }
    }

    return print_up();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (auto i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<string> cmd(n);
        for (auto &el: cmd) {
            cin >> el;
        }
        cout << sol(cmd);
    }

    return 0;
}