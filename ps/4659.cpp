#include <bits/stdc++.h>

using namespace std;

char v[] = {'a', 'e', 'i', 'o', 'u'};

bool contains(string::const_iterator b, string::const_iterator e) {
    for (auto i = 0; i < 5; ++i) {
        if (find(b, e, v[i]) != e) {
            return true;
        }
    }
    return false;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    string str;

    while (cin >> str) {
        if (str == "end") {
            return 0;
        }
        if (!contains(str.begin(), str.end())) {
            cout << '<' << str << "> is not acceptable.\n";
            continue;
        }

        if (str.size() >= 3) {
            bool temp = false;
            auto iter = str.begin();
            while (iter + 2 != str.end()) {
                bool a, b, c;
                a = contains(iter, iter + 1);
                b = contains(iter + 1, iter + 2);
                c = contains(iter + 2, iter + 3);
                if (a == b && b == c && c == a) {
                    temp = true;
                    break;
                }
                ++iter;
            }
            if (temp) {
                cout << '<' << str << "> is not acceptable.\n";
                continue;
            }
        }

        if (str.size() >= 2) {
            bool do_continue = false;
            auto iter = str.begin();
            while (iter + 1 != str.end()) {
                auto q = "ee";
                auto w = "oo";
                if (*iter == *(iter + 1)) {
                    auto e = string(iter, iter + 2);
                    if (e != q && e != w) {
                        cout << '<' << str << "> is not acceptable.\n";
                        do_continue = true;
                        break;
                    }
                }
                ++iter;
            }
            if (do_continue) continue;
        }

        cout << '<' << str << "> is acceptable.\n";
    }
}