#include <bits/stdc++.h>

using namespace std;

int n, mp, mf, ms, mv;
int cost = -1;
vector<int> v_ans;
string s_ans;

string str_of(int i) {
    string ret;

    for (auto j = 0; j < n; ++j) {
        if (i & 1 << j) {
            ret.append(to_string(j + 1));
            ret.append(" ");
        }
    }

    return ret;
}

bool meet_mn(int i, const vector<vector<int>> &vec) {
    int cp = 0, cf = 0, cs = 0, cv = 0;
    for (auto j = 0; j < n; ++j) {
        if (i & 1 << j) {
            cp += vec[j][0];
            cf += vec[j][1];
            cs += vec[j][2];
            cv += vec[j][3];
        }
    }
    return cp >= mp && cf >= mf && cs >= ms && mv <= cv;
}

int sum_of(int i, const vector<vector<int>> &vec) {
    int ret = 0;
    for (auto j = 0; j < n; ++j) {
        if (i & 1 << j) ret += vec[j][4];
    }
    return ret;
}

void sol(const vector<vector<int>> &vec) {
    int mn = INT_MAX, mn_i = -1;
    for (auto i = 0; i < 1 << n; ++i) {
        if (!meet_mn(i, vec)) continue;
        if (sum_of(i, vec) < mn) {
            mn = sum_of(i, vec);
            mn_i = i;
            s_ans = str_of(i);
        } else if(sum_of(i, vec) == mn && str_of(i) < s_ans){
            mn_i = i;
            s_ans = str_of(i);
        }
    }
    if (mn_i == -1) return;
    cost = mn;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> mp >> mf >> ms >> mv;

    vector<vector<int>> vec(n, vector<int>(5));
    for (auto i = 0; i < n; ++i) {
        cin >> vec[i][0];
        cin >> vec[i][1];
        cin >> vec[i][2];
        cin >> vec[i][3];
        cin >> vec[i][4];
    }

    sol(vec);

    cout << cost << '\n' << s_ans;
}