#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <list>
#include <vector>

using namespace std;

int a() {
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> h_list;
    string temp;

    for (auto i = 0; i < 9; i++) {
        cin >> temp;
        h_list.push_back(stoi(temp));
    }

    sort(h_list.begin(), h_list.end());
    do {
        auto a = accumulate(h_list.begin(), h_list.begin() + 7, 0);
        if (a == 100) {
            break;
        }
    } while (next_permutation(h_list.begin(), h_list.end()));

    sort(h_list.begin(), h_list.begin() + 7);

    for (auto i = 0; i < 7; ++i) {
        cout << h_list[i] << endl;
    }

    return 0;
}

int p2309() {
    list<int> h_list;
    string temp;

    while (cin >> temp) {
        h_list.push_back(stoi(temp));
    }
//
//    for (auto i = 0; i < 9; i++) {
//        cin >> temp;
//        h_list.push_back(stoi(temp));
//    }

    int total = accumulate(h_list.begin(), h_list.end(), 0);
    int target = total - 100;

    list<int>::iterator i, j;

    for (i = h_list.begin(); i != h_list.end(); ++i) {
        j = find(i, h_list.end(), target - *i);
        if (j != h_list.end()) {
            break;
        }
    }

    h_list.erase(i);
    h_list.erase(j);

    h_list.sort();
    i = h_list.begin();
    while (i != h_list.end()) {
        cout << *i << endl;
        ++i;
    }

    return 0;
}
