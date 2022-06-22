#include <bits/stdc++.h>

using namespace std;

int n;
string in;

stack<string> s;

bool is_num(const string &str) {
    return str != "(" && str != ")";
}

void handle(const string &str) {
    if (str == "(") {
        s.push(str);
    } else if (str == ")") {
        if (s.top() == ")") s.push(str);
        else if (s.top() == "(") {
            s.pop();
            handle("2");
        } else {
            auto t = s.top();
            s.pop();
            if (s.empty()) {
                s.push(t);
                s.push(str);
            }
            if (s.top() == "(") {
                s.pop();
                handle(to_string(2 + stoi(t)));
            } else {
                s.push(t);
                s.push(str);
            }
        }
    } else {
        if (s.empty()) {
            s.push(str);
            return;
        }
        if (s.top() == ")") {
            s.push(str);
        } else if (s.top() == "(") {
            s.push(str);
        } else {
            auto t = s.top();
            s.pop();
            handle(to_string(stoi(t) + stoi(str)));
        }
    }
}

void make_stack() {
    s.push(string(1, in[0]));
    for (auto i = 1; i < in.size(); ++i) {
        handle(string(1, in[i]));
    }
}

int find_max() {
    int ret = 0;

    while (!s.empty()) {
        auto cur = s.top();
        s.pop();
        if (is_num(cur)) ret = max(ret, stoi(cur));
    }

    return ret;
}

int sol() {
    make_stack();
    return find_max();
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> in;

    cout << sol();

    return 0;
}