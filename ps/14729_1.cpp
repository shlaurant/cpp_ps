#include <bits/stdc++.h>

using namespace std;

int n;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    priority_queue<string> scores;
    cin >> n;
    for (auto i = 0; i < n; ++i) {
        string el;
        cin >> el;
        while (el.size() < 7) {
            el.insert(0, "0");
        }
        scores.push(el);
        if (scores.size() > 7) scores.pop();
    }
    stack<string> s;
    while (!scores.empty()) {
        s.push(scores.top());
        scores.pop();
    }

    while (!s.empty()) {
        auto it = s.top().begin();
        while (*it == '0') {
            ++it;
        }
        cout << string(it, s.top().end()) << '\n';
        s.pop();
    }

    return 0;
}