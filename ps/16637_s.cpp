#include <bits/stdc++.h>

using namespace std;

int n, num[10];
char op[9];

int calc(int a, int b, char oper) {
    switch (oper) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
    }
}

void dfs(int op_i, int acc, int &ret) {
    if (op_i >= n / 2) {
        ret = max(acc, ret);
        return;
    }
    dfs(op_i + 1, calc(acc, num[op_i + 1], op[op_i]), ret);
    if (op_i + 1 < n / 2)
        dfs(op_i + 2,
            calc(acc, calc(num[op_i + 1], num[op_i + 2], op[op_i+1]), op[op_i]),
            ret);
}

int sol() {
    int ret = INT_MIN;
    dfs(0, num[0], ret);
    return ret;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (auto i = 0; i < n; ++i) {
        i % 2 == 0 ?
        cin >> num[i / 2] : cin >> op[i / 2];
    }

    cout << sol();
}