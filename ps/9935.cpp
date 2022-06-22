#include <bits/stdc++.h>

using namespace std;

string in;
string bomb;
string none = "FRULA";

stack<string> s;

string::iterator find_sub_end(string::iterator b) {
    auto bit = bomb.begin();
    while (*b == *bit && b != in.end() && bit != bomb.end()) {
        ++b;
        ++bit;
    }
    return b;
}

void clear_stack(string &ret) {
    string str;
    while (!s.empty()) {
        str.insert(0, s.top());
        s.pop();
    }
    ret.append(str);
}

string::iterator handle_stack(string::iterator b, string &ret) {
    while (!s.empty()) {
        auto str = s.top();
        int sz = bomb.size() - str.size();
        if (in.end() - b < sz) {
            clear_stack(ret);
            return b;
        }
        if (str.append(string(b, b + sz)) == bomb) {
            s.pop();
            b += sz;
        } else {
            clear_stack(ret);
            return b;
        }
    }
    return b;
}

bool is_bomb(string::iterator it) {
    if ((it - in.begin()) + bomb.size() > in.size()) return false;
    return string(it, it + bomb.size()) == bomb;
}

string sol() {
    string ret;

    auto it = in.begin();
    while (it != in.end()) {
        if (*it != bomb[0]) {
            clear_stack(ret);
            auto _it = find(it, in.end(), bomb[0]);
            ret.append(it, _it);
            it = _it;
        } else {
            if (is_bomb(it)) {
                it = handle_stack(it + bomb.size(), ret);
            } else {
                auto _it = find_sub_end(it);
                s.push(string(it, _it));
                it = _it;
            }
        }
    }

    if (!s.empty()) {
        clear_stack(ret);
    }

    return ret.empty() ? none : ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> in;
    cin >> bomb;

    cout << sol();

    return 0;
}