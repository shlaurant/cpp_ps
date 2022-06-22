#include <bits/stdc++.h>

using namespace std;

vector<string> split(string input, const string &d) {
    vector<string> ret;

    if (input.find(d) != string::npos) {
        ret.push_back(input.substr(0, input.find(d)));
        input.erase(0, input.find(d) + d.length());
    }

    ret.push_back(input);
    return ret;
}

int main() {
    int num;
    cin >> num;

    string input, pre, suf;
    cin >> input;
    pre = input.substr(0, input.find('*'));
    suf = input.substr(input.find('*') + 1);

    for (auto i = 0; i < num; ++i) {
        auto ret = "NE";
        cin >> input;
        if (input.size() >= pre.size() + suf.size()) {
            if (pre == input.substr(0, pre.size()) &&
                suf == input.substr(input.size() - suf.size())) {
                ret = "DA";
            }
        }
        cout << ret << endl;
    }

    return 0;
}