#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> in;

vector<int> plug;
vector<bool> v;

int _opt(int el, int i) {
    int ret = INT_MAX;

    while (i < k) {
        if (in[i] == el) {
            ret = i;
            break;
        }
        ++i;
    }

    return ret;
}

int opt_el(int i) {
    int ret;
    int curfar = 0;
    for (auto el: plug) {
        if (_opt(el, i) > curfar) {
            ret = el;
            curfar = _opt(el, i);
        }
    }

    return ret;
}

int sol() {
    int ret = 0;

    v.resize(k + 1);

    for (auto i = 0; i < k; ++i) {
        if (v[in[i]]) continue;
        if (plug.size() == n) {
            int oe = opt_el(i + 1);
            v[oe] = false;
            plug.erase(find(plug.begin(), plug.end(), oe));
            ++ret;
        }
        plug.push_back(in[i]);
        v[in[i]] = true;
    }

    return ret;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    in.resize(k);
    for (auto &el: in) {
        cin >> el;
    }

    cout << sol();

    return 0;
}