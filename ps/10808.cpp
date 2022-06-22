#include <bits/stdc++.h>

using namespace std;

int a(){
    cin.tie(NULL);
    cout.tie(NULL);

    map<char, int> answer;

    for(auto i = 'a'; i <= 'z'; ++i){
        answer[i] = 0;
    }

    string input;
    cin >> input;

    for (char & i : input){
        ++answer[i];
    }

    auto iter = answer.begin();
    cout << iter->second;
    ++iter;
    while(iter != answer.end()){
        cout << " " << iter->second;
        ++iter;
    }
}