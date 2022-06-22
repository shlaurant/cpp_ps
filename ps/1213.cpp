#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    string result = "I'm Sorry Hansoo";

    int a[26] = {0,};
    string input;
    cin >> input;
    for (const char &c: input) {
        ++a[c - 'A'];
    }

    int n = 0;
    int ix = -1;

    for (auto i = 0; i < 26; ++i) {
        if (a[i] % 2 != 0) {
            ++n;
            ix = i;
        }
    }

    if (n <= 1) {
        result = "";
        for (auto i = 0; i < 26; ++i) {
            result += string(a[i] / 2, i + 'A');
        }
        auto temp = result;
        reverse(temp.begin(), temp.end());
        if (n == 1) {
            result += ix + 'A';
        }
        result += temp;
    }

    cout << result;
    return 0;
}