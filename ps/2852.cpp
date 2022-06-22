#include <bits/stdc++.h>

using namespace std;

int n, t;
int s[2] = {0,};
int ret[2] = {0,};

void calc(int b, int e) {
    if (s[0] > s[1]) {
        ret[0] += e - b;
    } else if (s[1] > s[0]) {
        ret[1] += e - b;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int ct = 0;
    for (auto i = 0; i < n; ++i) {
        int team;
        cin >> team;
        int a, b;
        scanf("%d:%d", &a, &b);
        calc(ct, 60 * a + b);
        ++s[team - 1];
        ct = 60 * a + b;
    }
    calc(ct, 60 * 48);

    printf("%02d:%02d\n", ret[0] / 60, ret[0] % 60);
    printf("%02d:%02d\n", ret[1] / 60, ret[1] % 60);
}