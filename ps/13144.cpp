#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> p;

vector<bool> v;
queue<int> q;

long long sol() {
    long long ret = 0;
    v.resize(100001);

    for (auto el: p) {
        if (!v[el]) {
            q.push(el);
            ret += q.size();
            v[el] = true;
        } else {
            while (q.front() != el) {
                v[q.front()] = false;
                q.pop();
            }
            q.pop();
            q.push(el);
            ret += q.size();
        }
    }

    return ret;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    p.resize(n);
    for (auto &el: p) {
        cin >> el;
    }

    cout << sol();

    return 0;
}