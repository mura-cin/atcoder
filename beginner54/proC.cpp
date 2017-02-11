#include <iostream>
using namespace std;

const int MAX_N = 10;

int N, M;
int adj[MAX_N][MAX_N];
bool used[MAX_N];

bool check() {
    bool ret = true;
    for (int i = 1; i <= N; i++) {
        if (!used[i]) ret = false;
    }
    return ret;
}

int dfs(int s) {
    used[s] = true;
    if (check()) {
        used[s] = false;
        return 1;
    }

    int ret = 0;
    for (int i = 1; i <= N; i++) {
        if (adj[s][i] == 1 && !used[i]) {
            ret += dfs(i);
        }
    }

    used[s] = false;
    return ret;
}

int main(void) {

    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            adj[i][j] = 0;
        }
    }
    for (int i = 0; i < MAX_N; i++) used[i] = false;

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    cout << dfs(1) << endl;

    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= N; j++) {
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}
