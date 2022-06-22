#include <bits/stdc++.h>

using namespace std;

int p1159() {
    int x[26] = {0,};
    string input;
    cin >> input;

    int i = stoi(input);

    for (auto n = 0; n < i; ++n) {
        cin >> input;
        ++x[input[0] - 'a'];
    }

    bool has = false;

    for (auto j = 0; j < 26; ++j) {
        if (x[j] >= 5) {
            cout << (char)(j + 'a');
            has = true;
        }
    }

    if(!has){
        cout << "PREDAJA";
    }

    return 0;
}