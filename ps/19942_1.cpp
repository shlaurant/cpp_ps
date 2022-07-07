#include <bits/stdc++.h>

using namespace std;

struct ind {
    int p, f, s, v, c;
};

int n;
int mp, mf, ms, mv;
vector<ind> input;

int cost = INT_MAX;
string av;

vector<int> cand;

bool meet(int info) {
    int cp = 0, cf = 0, cs = 0, cv = 0;
    for (auto i = 0; i < n; ++i) {
        if (info & (1 << i)) {
            cp += input[i].p;
            cf += input[i].f;
            cs += input[i].s;
            cv += input[i].v;
        }
    }
    return cp >= mp && cf >= mf && cs >= ms && cv >= mv;
}

int cost_of(int info) {
    int ret = 0;
    for (auto i = 0; i < n; ++i) {
        if (info & (1 << i)) {
            ret += input[i].c;
        }
    }
    return ret;
}

void sol() {

    for (auto i = 1; i < (1 << n); ++i) {
        if (meet(i)) {
            auto c = cost_of(i);
            if (c < cost) {
                cand.clear();
                cand.push_back(i);
                cost = c;
            } else if (c == cost) {
                cand.push_back(i);
            }
        }
    }

    if (cost == INT_MAX) {
        cost = -1;
    } else {
        vector<string> temp;
        for (auto el: cand) {
            string str;
            for (auto i = 0; i < n; ++i) {
                if (el & (1 << i)) str += to_string(i + 1) + " ";
            }
            temp.push_back(str);
        }
        sort(temp.begin(), temp.end());
        av = temp.front();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> mp >> mf >> ms >> mv;
    input.resize(n);
    for (auto &el: input) {
        cin >> el.p >> el.f >> el.s >> el.v >> el.c;
    }

    sol();

    cout << cost << endl;
    if (cost != -1) {
        cout << av;
    }

    return 0;
}