#include <bits/stdc++.h>

using namespace std;

int n;
char c[19];

char op_arr[] = {'*', '-', '+'};

bool is_num(char t) {
    return '0' <= t && t <= '9';
}

bool is_op(char t) {
    return find(op_arr, op_arr + 3, t) != op_arr + 3;
}

string _calc(string a, char op, string b) {
    string ret;
    int _a, _b;
    _a = stoi(a);
    _b = stoi(b);
    switch (op) {
        case '+':
            ret = to_string(_a + _b);
            break;
        case '-':
            ret = to_string(_a - _b);
            break;
        case '*':
            ret = to_string(_a * _b);
            break;
        default:
            break;
    }
    return ret;
}

void _pop(stack<string> &s) {
    if (s.size() <= 1) return;
    string a, b;
    char op;
    b = s.top();
    s.pop();
    op = s.top()[0];
    if (!is_op(op)) {
        s.push(b);
        return;
    }
    s.pop();
    a = s.top();
    s.pop();
    s.push(_calc(a, op, b));
}


int calc(const vector<char> &ex) {
    stack<string> s;
    for (auto el: ex) {
        if (s.empty()) {
            s.push(string(1, el));
            continue;
        }
        if (is_num(el) && is_op(s.top()[0])) {
            s.push(string(1, el));
            _pop(s);
        } else if (el == ')') {
            string t = s.top();
            s.pop();
            s.pop();
            s.push(t);
            _pop(s);
        } else {
            s.push(string(1, el));
        }
    }
    return stoi(s.top());
}

void dfs(vector<char> &cur_ex, int cur_i, int num_p, int &cur_max) {
    if (cur_i + 2 >= n || num_p == 0) {
        vector<char>::size_type s_ori = cur_ex.size();
        for (auto i = cur_i; i < n; ++i) {
            cur_ex.push_back(c[i]);
        }
        cur_max = max(cur_max, calc(cur_ex));
        cur_ex.erase(cur_ex.begin() + s_ori, cur_ex.end());
        return;
    }
    if (is_op(c[cur_i])) {
        cur_ex.push_back(c[cur_i]);
        dfs(cur_ex, cur_i + 1, num_p, cur_max);
        cur_ex.erase(--cur_ex.end());
        return;
    }
    auto s_ori = cur_ex.size();
    for (auto i = cur_i; i < n; i += 2) {
        if (i == n - 1) break;
        cur_ex.insert(cur_ex.end(), c + cur_i, c + i);
        cur_ex.push_back('(');
        cur_ex.insert(cur_ex.end(), c + i, c + i + 3);
        cur_ex.push_back(')');
        dfs(cur_ex, i + 3, num_p - 1, cur_max);
        cur_ex.erase(cur_ex.begin() + s_ori, cur_ex.end());
    }
    return;
}

int max_when(int num_p) {
    vector<char> cur_ex;
    int cur_i = 0;
    int cur_max = INT_MIN;
    dfs(cur_ex, cur_i, num_p, cur_max);
    return cur_max;
}

int sol() {
    int ret = INT_MIN;
    int max_p = (n + 1) / 4;
    for (auto i = 0; i <= max_p; ++i) {
        ret = max(ret, max_when(i));
    }
    return ret;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (auto i = 0; i < n; ++i) {
        cin >> c[i];
    }

    cout << sol();
}