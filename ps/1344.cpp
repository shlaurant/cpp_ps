#include <bits/stdc++.h>

using namespace std;

int a, b;

vector<vector<double>> av;
vector<vector<double>> bv;

vector<bool> sifter;

double ap, bp;

void make_sifter() {
    sifter.resize(19, true);
    sifter[0] = false;
    sifter[1] = false;
    for (auto i = 2; i < 19; ++i) {
        if (sifter[i]) {
            for (auto j = 2 * i; j < 19; j += i) {
                sifter[j] = false;
            }
        }
    }
}

void calc(vector<vector<double>> &v, double p) {
    for (auto time = 0; time < 18; ++time) {
        for (auto goal = 0; goal <= time; ++goal) {
            v[time + 1][goal + 1] += v[time][goal] * p;
            v[time + 1][goal] += v[time][goal] * (1 - p);
        }
    }
}

double sum_of_not(const vector<vector<double>> &v) {
    double ret = 0;

    for (auto i = 0; i < 19; ++i) {
        if (!sifter[i]) ret += v[18][i];
    }

    return ret;
}

double sol() {
    av.resize(19, vector<double>(18));
    bv.resize(19, vector<double>(18));
    av[0][0] = 1;
    bv[0][0] = 1;

    ap = (double) a / 100;
    bp = (double) b / 100;

    calc(av, ap);
    calc(bv, bp);
    make_sifter();

    return 1 - sum_of_not(av) * sum_of_not(bv);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b;

    cout << sol();

    return 0;
}