#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<char>> paper;

vector<vector<bool>> v;
int ans = 0;

pair<int, int> find_nonv() {
    for (auto i = 0; i < n; ++i) {
        for (auto j = 0; j < m; ++j) {
            if (!v[i][j]) return {i, j};
        }
    }

    return {-1, -1};
}

void dfs(int sum) {
    int y, x;
    tie(y, x) = find_nonv();
    if (y == -1) {
        ans = max(ans, sum);
        return;
    }

    int i = 0;
    string c_sum;
    while (y + i < n && !v[y + i][x]) {
        v[y + i][x] = true;
        c_sum += paper[y + i][x];
        dfs(sum + stoi(c_sum));
        ++i;
    }
    while (i > 0) {
        --i;
        v[y + i][x] = false;
    }

    c_sum = "";
    while (x + i < m && !v[y][x + i]) {
        v[y][x + i] = true;
        c_sum += paper[y][x + i];
        dfs(sum + stoi(c_sum));
        ++i;
    }
    while (i > 0) {
        --i;
        v[y][x + i] = false;
    }
}

int sol() {
    v.resize(n, vector<bool>(m));
    dfs(0);
    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m;
    paper.resize(n, vector<char>(m));
    for (auto &rw: paper) {
        for (auto &el: rw) {
            cin >> el;
        }
    }

    cout << sol();

    return 0;
}