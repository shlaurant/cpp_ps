#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str, front, back;
    cin >> str;
    front = string(str.begin(), str.begin() + str.size() / 2);
    back = string(str.begin() + (str.size() + 1) / 2, str.end());
    reverse(front.begin(), front.end());

    front == back ? cout << 1 : cout << 0;

    return 0;
}