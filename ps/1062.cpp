#include <bits/stdc++.h>

using namespace std;

int k, n;
vector<string> in;
string pre = "anta", suf = "tica";

bool dic[26];
int fix[] = {0, 13, 19, 8, 2};

bool is_valid(int i) {
    int sum = 0;
    for (auto j = 0; j < 26; ++j) {
        if (i & 1 << j) {
            ++sum;
        } else {
            if (find(fix, fix + 5, j) != fix + 5) return false;
        }
    }
    return sum == k;
}

void set_dic(int i) {
    for (int j = 0; j < 26; ++j) {
        if (i & 1 << j) dic[j] = true;
    }
}

int count_now() {
    int ret = 0;

    for (const auto &str: in) {
        bool good = true;
        for (auto i = 4; i < str.size() - 4; ++i) {
            if (!dic[str[i] - 'a']) {
                good = false;
                break;
            }
        }
        if (good) ++ret;
    }

    return ret;
}

int sol() {
    int ret = INT_MIN;
    fill(dic, dic + 26, false);

    if (k < 5) return 0;
    for (auto i = 0; i < 1 << 26; ++i) {
        if (is_valid(i)) {
            set_dic(i);
            ret = max(ret, count_now());
            fill(dic, dic + 26, false);
        }
    }

    return ret;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    in.resize(n);
    for (auto &el: in) {
        cin >> el;
    }

    cout << sol();
}