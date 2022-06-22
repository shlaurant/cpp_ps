#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node *p = nullptr;
    vector<Node *> c;
};

int n, m;
Node *r = nullptr;
Node *arr[50] = {nullptr,};

void rm(const Node *np) {
    *find(arr, arr + n, np) = nullptr;
    if (np->p != nullptr) {
        np->p->c.erase(find(np->p->c.begin(), np->p->c.end(), np));
    }
    for (const auto &p: np->c) {
        rm(p);
    }
    delete np;
}

int sol(int x) {
    int ret = 0;

    rm(arr[x]);

    for (const auto &item: arr) {
        if (item != nullptr) {
            if (item->c.empty()) ++ret;
        }
    }
    return ret;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (auto i = 0; i < n; ++i) {
        arr[i] = new Node();
    }

    for (auto i = 0; i < n; ++i) {
        cin >> m;
        if (m != -1) {
            arr[i]->p = arr[m];
            arr[m]->c.push_back(arr[i]);
        }
    }

    cin >> m;
    cout << sol(m);

    return 0;
}