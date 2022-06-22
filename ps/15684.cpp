#include <bits/stdc++.h>

using namespace std;

int n, m, h;

bool is_good(const vector<vector<int>> &ladder) {
    bool ret = true;

    for (auto i = 0; i < ladder.size(); ++i) {
        int cur_l = i;
        for (auto j = 0; j < ladder[i].size(); ++j) {
            if (ladder[cur_l][j] != -1) cur_l = ladder[cur_l][j];
        }
        if (cur_l != i) {
            ret = false;
            break;
        }
    }

    return ret;
}

bool possible_when(int cnt, vector<vector<int>> &ladder, int v) {
    if (cnt == 0) return is_good(ladder);

    for (auto ver = v; ver < ladder.size() - 1; ++ver) {
        for (auto hor = 0; hor < ladder[0].size(); ++hor) {
            if (ladder[ver][hor] != -1) continue;
            if (ladder[ver + 1][hor] != -1) continue;
            ladder[ver][hor] = ver + 1;
            ladder[ver + 1][hor] = ver;
            if (possible_when(cnt - 1, ladder, ver)) return true;
            ladder[ver][hor] = -1;
            ladder[ver + 1][hor] = -1;
        }
    }
    return false;
}

int sol(vector<vector<int>> &ladder) {
    for (auto i = 0; i < 4; ++i) {
        if (possible_when(i, ladder, 0)) return i;
    }
    return -1;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> h;
    vector<vector<int>> ladder(n, vector<int>(h, -1));

    int a, b;
    for (auto i = 0; i < m; ++i) {
        cin >> a >> b;
        ladder[b - 1][a - 1] = b;
        ladder[b][a - 1] = b - 1;
    }

    cout << sol(ladder);
}