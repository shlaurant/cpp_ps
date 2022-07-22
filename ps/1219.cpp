#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mn = LONG_LONG_MIN;

struct edge {
    int u, v, d;
};

int n, s, e, m;
vector<edge> ev;
vector<int> profit;

vector<ll> dist;
vector<vector<int>> dist_fw;

string sol();
void make_fw();
void iterate();
bool not_ok();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> s >> e >> m;
    ev.resize(m);
    for (auto &el: ev) {
        cin >> el.u >> el.v >> el.d;
    }

    profit.resize(n);
    for (auto &el: profit) {
        cin >> el;
    }

    cout << sol();

    return 0;
}

string sol() {
    dist.resize(n, mn);
    dist[s] = profit[s];

    make_fw(); //플로이드-워셜 거리 배열 생성
    iterate(); //벨만포드 한번 돌리기
    if (dist[e] == mn) return "gg"; // e까지의 경로가 생성되지 않았다면 gg리턴
    if (not_ok()) return "Gee"; //양의 사이클이 있는지, 있다면 e까지 연결되는지 검사
    return to_string(dist[e]);
}

void make_fw() {
    dist_fw.resize(n, vector<int>(n, INT_MAX));
    for (auto i = 0; i < n; ++i) {
        dist_fw[i][i] = 0;
    }
    for (const auto &el: ev) {
        dist_fw[el.u][el.v] = 1;//u-v를 잇는 간선이 몇개건, 얼마나 걸리건 있다는 사실만 확인하면 된다
    }
    for (auto k = 0; k < n; ++k) {
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < n; ++j) {
                if (dist_fw[i][k] == INT_MAX ||dist_fw[k][j] == INT_MAX) continue;
                dist_fw[i][j] = min(dist_fw[i][j], dist_fw[i][k] + dist_fw[k][j]);
                //사실 몇으로 처리되건 상관없고, 마찬가지로 경로가 있다는 사실만 확인하면 됨
            }
        }
    }
}

void iterate() {
    for (auto i = 0; i < n - 1; ++i) {
        for (const auto &el: ev) {
            if (dist[el.u] == mn) continue;
            if (dist[el.v] < dist[el.u] - el.d + profit[el.v])
                dist[el.v] = dist[el.u] - el.d + profit[el.v];
        }
    }
}

bool not_ok() {
    for (const auto &el: ev) {
        if (dist[el.u] == mn) continue;
        if (dist[el.v] < dist[el.u] - el.d + profit[el.v]) {
            dist[el.v] = dist[el.u] - el.d + profit[el.v];
            if (dist_fw[el.v][e] != INT_MAX) return true;//INT_MAX가 아니라는것은 v-e경로가 존재함을 뜻함
        }
    }
    return false;
}
