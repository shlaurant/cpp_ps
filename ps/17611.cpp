#include <bits/stdc++.h>

using namespace std;

const int mx = 500000;

int n;

vector<pair<int, int>> hor;
vector<pair<int, int>> ver;

vector<bool> used_x;
vector<bool> used_y;

vector<int> fwl;
vector<int> fwr;

int query(const vector<int> &fw, int index) {
    index += 1;
    int ret = 0;
    while (index > 0) {
        ret += fw[index];
        index -= index & (-index);
    }
    return ret;
}

void update(vector<int> &fw, int index, int val) {
    index += 1;
    while (index < fw.size()) {
        fw[index] += val;
        index += index & (-index);
    }
}

int sol(const vector<pair<int, int>> &vec, const vector<bool> &visit) {
    fwl.resize(mx * 2 + 1 + 1);
    fwr.resize(mx * 2 + 1 + 1);
    fill(fwl.begin(), fwl.end(), 0);
    fill(fwr.begin(), fwr.end(), 0);


    for (const auto &el: vec) {
        update(fwl, el.first + mx, 1);
        update(fwr, el.second + mx, 1);
    }

    int ret = 0;
    for (auto i = 1; i <= 2 * mx; ++i) {
        ret = max(ret, query(fwl, i - 1) - query(fwr, i - 1));
    }
    return ret;
}

int sol() {
    return max(sol(hor, used_x), sol(ver, used_y));
}

int main() {
    used_x.resize(2 * mx + 1);
    used_y.resize(2 * mx + 1);

    cin >> n;
    int x, y, ix, iy;
    int nx, ny;
    cin >> x >> y;
    ix = x;
    iy = y;
    used_x[x + mx] = true;
    used_y[y + mx] = true;

    for (auto i = 1; i < n; ++i) {
        cin >> nx >> ny;
        used_x[nx + mx] = true;
        used_y[ny + mx] = true;

        if (nx == x) {
            ver.push_back({min(y, ny), max(y, ny)});
        } else {
            hor.push_back({min(x, nx), max(x, nx)});
        }
        x = nx;
        y = ny;
    }

    if (x == ix) {
        ver.push_back({min(y, iy), max(y, iy)});
    } else {
        hor.push_back({min(x, ix), max(x, ix)});
    }

    cout << sol();

    return 0;
}