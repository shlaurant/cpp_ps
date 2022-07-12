#include <bits/stdc++.h>

using namespace std;

int m;

vector<long long> cnt;

void make_cnt() {
    cnt.push_back(0);
    cnt.push_back(5);
    cnt.push_back(13);
    long long sum;
    int index = 3;
    while (true) {
        sum = cnt[index - 1] + cnt[index - 2] + 1;
        if (sum > 2ll * INT_MAX) break;
        cnt.push_back(sum);
        ++index;
    }
}

int find_n(int val) {
    int l = 1, r = cnt.size();
    while (l < r) {
        auto mid = (l + r) / 2;
        if (cnt[mid] >= val) {
            return mid;
        } else {
            l = mid + 1;
        }
    }
}

string sol() {
    make_cnt();
    int n = find_n(m);
    while (n > 2) {
        if (m > cnt[n - 1] + 1) {
            m -= cnt[n - 1] + 1;
            n -= 2;
        } else if (m <= cnt[n - 1]) {
            n -= 1;
        } else {
            return "Messi Messi Gimossi";
        }
    }

    if (n == 1) {
        string str = "Messi";
        return str.substr(m - 1, 1);
    } else {
        string str = "Messi Gimossi";
        auto ret = str.substr(m - 1, 1);
        if (ret != " ") return ret;
        else return "Messi Messi Gimossi";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> m;
    cout << sol();

    return 0;
}