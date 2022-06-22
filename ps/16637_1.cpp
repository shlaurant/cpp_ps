#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> nums;
vector<char> ops;

long long mx = LONG_LONG_MIN;

long long calc(long long l, long long r, char op) {
    switch (op) {
        case '+':
            return l + r;
        case '-':
            return l - r;
        case '*':
            return l * r;
    }
}

void dfs(int index, long long sum) {
    if (index == ops.size()) {
        mx = max(sum, mx);
        return;
    }

    dfs(index + 1, calc(sum, nums[index + 1], ops[index]));
    if (index + 1 < ops.size())
        dfs(index + 2,
            calc(sum, calc(nums[index + 1], nums[index + 2], ops[index + 1]),
                 ops[index]));
}

void sol() {
    dfs(0, nums[0]);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int a;
    char b;
    for (auto i = 0; i < (n - 1)/2; ++i) {
        cin >> a >> b;
        nums.push_back(a);
        ops.push_back(b);
    }
    cin >> a;
    nums.push_back(a);

    sol();

    cout << mx;
}