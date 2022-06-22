#include <bits/stdc++.h>

using namespace std;

void read(vector<int> &fees, int count) {
    string input;

    for (auto i = 0; i < count; ++i) {
        cin >> input;
        fees.push_back(stoi(input));
    }
}

int a() {
    cin.tie(NULL);
    cout.tie(NULL);

    int time[100] = {0,};

    vector<int> fees;
    vector<int> a;
    vector<int> b;
    vector<int> c;

    string input;

    read(fees, 3);
    read(a, 2);
    read(b, 2);
    read(c, 2);


    for (auto i = a[0]; i < a[1]; ++i) {
        ++time[i];
    }
    for (auto i = b[0]; i < b[1]; ++i) {
        ++time[i];
    }
    for (auto i = c[0]; i < c[1]; ++i) {
        ++time[i];
    }

    auto answer = 0;

    for (int i: time) {
        switch (i) {
            case 1:
                answer += fees[0];
                break;
            case 2:
                answer += fees[1] * 2;
                break;
            case 3:
                answer += fees[2] * 3;
                break;
            default:
                break;
        }
    }

    cout << answer;
}