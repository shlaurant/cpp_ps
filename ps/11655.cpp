#include <bits/stdc++.h>

using namespace std;

int main() {
    string input;
    getline(cin, input);

    for (char &i: input) {
        if (isalpha(i)) {
            int x;

            if ('A' <= i && i <= 'Z') {
                x = 'A';
            } else {
                x = 'a';
            }

            i = (i - x + 13) % 26 + x;
        }
    }

    cout << input;

    return 0;
}