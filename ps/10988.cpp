#include <bits/stdc++.h>

using namespace std;

int a() {
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    cin >> input;
    string x = input;

    reverse(input.begin(), input.end());

    x == input ? cout << 1 : cout << 0;

    return 0;
}