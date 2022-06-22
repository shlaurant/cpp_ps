#include <bits/stdc++.h>

using namespace std;

int k;
vector<char> in;

char nums[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
vector<string> ans;

bool oper(char l, char r, char op) {
    switch (op) {
        case '>':
            return l > r;
            break;
        case '<':
            return l < r;
            break;
        default:
            throw domain_error("??");
    }
}

bool good() {
    for (auto i = 0; i < k; ++i) {
        if (!oper(nums[i], nums[i + 1], in[i])) return false;
    }
    return true;
}

void sol() {
    do {
        if (good()) ans.push_back(string(nums, nums + k+1));
    } while (next_permutation(nums, nums + 10));
    sort(ans.begin(), ans.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    in.resize(k);
    for (auto &el: in) {
        cin >> el;
    }

    sol();

    cout << ans[ans.size() - 1] << '\n';
    cout << ans[0] << '\n';

    return 0;
}