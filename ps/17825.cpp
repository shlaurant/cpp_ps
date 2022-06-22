#include <bits/stdc++.h>

using namespace std;

class Map {
public:
    struct Node {
        int val = 0;
        Node *n = nullptr;
        Node *m = nullptr;
    };

    Map() {
        r = new Node();
        e = new Node();
        auto t = r;
        for (auto i = 2; i <= 40; i += 2) {
            t->n = new Node();
            t->n->val = i;
            t = t->n;
            if (i == 10) exs[0] = t;
            if (i == 20) exs[1] = t;
            if (i == 30) exs[2] = t;
        }
        auto n40 = t;
        t->n = e;

        auto n25 = new Node();
        n25->val = 25;

        int arr0[] = {13, 16, 19};
        t = create(arr0, 3);
        exs[0]->m = t;
        t->n->n->n = n25;

        int arr1[] = {22, 24};
        t = create(arr1, 2);
        exs[1]->m = t;
        t->n->n = n25;

        int arr2[] = {28, 27, 26};
        t = create(arr2, 3);
        exs[2]->m = t;
        t->n->n->n = n25;

        int arr3[] = {30, 35};
        t = create(arr3, 2);
        n25->n = t;
        t->n->n = n40;
    }

    Node *root() const { return r; }
    const Node *end() const { return e; }
    bool is_avail(Node *p, int i, Node *tks[4]) const {
        bool ret = true;
        auto n = next(p, i);
        if (find(tks, tks + 4, n) != tks + 4 && n != e) ret = false;
        return ret;
    }
    Node *next(Node *p, int i) const {
        if (p == e) return p;

        if (find(exs, exs + 3, p) != exs + 3) return next(p->m, i - 1);

        Node *ret = p;
        for (auto j = 0; j < i; ++j) {
            if (ret->n == nullptr) break;
            ret = ret->n;
        }
        return ret;
    }

private:
    Node *r;
    Node *e;
    Node *exs[3];

    Node *create(int val[], ptrdiff_t s) {
        Node *ret;
        Node *t = nullptr;
        for (ptrdiff_t i = 0; i < s; ++i) {
            auto q = new Node();
            q->val = val[i];
            if (t == nullptr) {
                ret = t = q;
            } else {
                t->n = q;
                t = q;
            }
        }
        return ret;
    }
};

int dice[10];
Map::Node *token[4] = {nullptr};
Map *mp;

int go(int t) {
    if (t >= 10) return 0;
    int ret = 0;

    for (auto &np: token) {
        if (mp->end() == np || !mp->is_avail(np, dice[t], token)) continue;
        auto ori = np;
        np = mp->next(np, dice[t]);
        ret = max(ret, np->val + go(t + 1));
        np = ori;
    }

    return ret;
}

int sol() {
    return go(0);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    mp = new Map();
    for (auto &p: token) {
        p = mp->root();
    }

    for (int & i : dice) {
        cin >> i;
    }

    cout << sol();
}