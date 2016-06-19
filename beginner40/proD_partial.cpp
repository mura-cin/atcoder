#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100000;

struct edge {
    int to, year;
    edge(int to, int year) {
        this->to = to;
        this->year = year;
    }
};
vector<edge> G[MAX_N+1];
bool used[MAX_N+1];

int dfs(int v, int w) {
    if (used[v]) return 0;

    used[v] = true;
    int ret = 1;
    for (int i = 0; i < G[v].size(); i++) {
        if (G[v][i].year > w) {
            ret += dfs(G[v][i].to, w);
        }
    }

    return ret;
}

int main(void) {

    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int s, t, y;
        scanf("%d %d %d", &s, &t, &y);
        G[s].emplace_back(t, y);
        G[t].emplace_back(s, y);
    }

    int Q;
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        int v, w; scanf("%d %d", &v, &w);
        fill(used, used+MAX_N+1, false);
        int ans = dfs(v, w);
        printf("%d\n", ans);
    }

    // for (int i = 1; i <= N; i++) {
    //     cout << "G[" << i << "]:" << endl;
    //     for (int j = 0; j < G[i].size(); j++) {
    //         cout << "to: " << G[i][j].to << ", year: " << G[i][j].year << endl;
    //     }
    // }

    return 0;
}
