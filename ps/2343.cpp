#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> lec;

vector<int> cl;

void make_cl() {
    cl.resize(n);
    cl.front() = lec.front();
    for (auto i = 1; i < n; ++i) {
        cl[i] = cl[i - 1] + lec[i];
    }
}

int count(int l) {
    int ret = 0;
    int pre_s = 0;

    for (auto i = 0; i < n; ++i) {
        if (cl[i] - pre_s > l) {
            pre_s = cl[i - 1];
            ++ret;
        }
    }

    return ret + 1;
}

int max_lec() {
    int ret = INT_MIN;

    for (auto el: lec) {
        if (el > ret) ret = el;
    }

    return ret;
}

int sol() {
    int ret = INT_MAX;

    make_cl();

    int l = max_lec(), r = cl.back() + 1;
    while (l < r) {
        int mid = (l + r) / 2;
        int cnt = count(mid);
        if (cnt > m) {
            l = mid + 1;
        } else {
            ret = min(ret, mid);
            r = mid;
        }
    }

    return ret;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    lec.resize(n);
    for (auto &el: lec) {
        cin >> el;
    }

    cout << sol();

    return 0;
}