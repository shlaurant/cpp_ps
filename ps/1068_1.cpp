#include <bits/stdc++.h>

using namespace std;

void dfs(const vector<pair<int, vector<int>>> &tree, vector<bool> &alive, int del) {
    alive[del] = false;
    for (auto child: tree[del].second) {
        dfs(tree, alive, child);
    }
}

int sol(vector<pair<int, vector<int>>> &tree, int del) {
    int ret = 0;
    vector<bool> alive(tree.size(), true);

    //delete
    int p = tree[del].first;
    if (p != -1) {
        auto it = find(tree[p].second.begin(), tree[p].second.end(), del);
        tree[p].second.erase(it);
    }
    dfs(tree, alive, del);

    for (auto i = 0; i < tree.size(); ++i) {
        if (tree[i].second.empty() && alive[i]) ++ret;
    }

    return ret;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    int n, del;
    cin >> n;
    vector<pair<int, vector<int>>> tree(n);

    for (auto i = 0; i < n; ++i) {
        cin >> tree[i].first;
        if (tree[i].first != -1) tree[tree[i].first].second.push_back(i);
    }

    cin >> del;

    cout << sol(tree, del);
}