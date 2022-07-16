#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int m = 1000000007;
const int st_sz = 200001;

struct node {
    ll l, r;

    node operator+(const node &rhs) const {
        return node{l + rhs.l, r + rhs.r};
    }

    node &operator+=(const node &rhs) {
        l += rhs.l;
        r += rhs.r;
        return *this;
    }
};

int n;
vector<int> coord;

vector<node> st_sum;
vector<int> st_cnt;

void cons_st_sum() {
    st_sum.resize(2 * st_sz, node{0, 0});
}

void cons_st_cnt() {
    st_cnt.resize(2 * st_sz, 0);
}

void update_sum(int index) {
    auto ori = index;
    index += st_sz;
    auto &t = st_sum[index];
    t.l += ori;
    t.r += st_sz - ori;
    while (index > 1) {
        st_sum[index >> 1] = st_sum[index] + st_sum[index ^ 1];
        index >>= 1;
    }
}

void update_cnt(int index) {
    index += st_sz;
    ++st_cnt[index];
    while (index > 1) {
        st_cnt[index >> 1] = st_cnt[index] + st_cnt[index ^ 1];
        index >>= 1;
    }
}

node query_s(int l, int r) {
    node ret{0, 0};

    l += st_sz;
    r += st_sz;
    while (l < r) {
        if (l & 1) {
            ret += st_sum[l++];
        }

        if (r & 1) {
            ret += st_sum[--r];
        }
        l >>= 1;
        r >>= 1;
    }
    return ret;
}

int query_c(int l, int r) {
    int ret = 0;
    l += st_sz;
    r += st_sz;
    while (l < r) {
        if (l & 1) ret += st_cnt[l++];
        if (r & 1) ret += st_cnt[--r];
        l >>= 1;
        r >>= 1;
    }
    return ret;
}

ll sum_at(int index) {
    auto lsum = query_s(0, index).l;
    auto lcnt = query_c(0, index);
    auto rsum = query_s(index, st_sz).r;
    auto rcnt = query_c(index, st_sz);
    ll ret = 0;

    ret += ((ll)lcnt * index) - lsum;
    ret += ((ll)rcnt * (st_sz - index)) - rsum;
    ret %= m;

    return ret;
}

ll sol() {
    ll ret = 1;
    cons_st_sum();
    cons_st_cnt();
    update_sum(coord[0]);
    update_cnt(coord[0]);

    for (auto i = 1; i < n; ++i) {
        ret *= sum_at(coord[i]);
        ret %= m;
        update_sum(coord[i]);
        update_cnt(coord[i]);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    coord.resize(n);
    for (auto &el: coord) {
        cin >> el;
    }
    cout << sol();

    return 0;
}