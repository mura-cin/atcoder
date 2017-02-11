#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 50;
const int MAX_AB = 500;
const int INF = 99999999;

int dp[MAX_N][MAX_AB][MAX_AB];

int main(void) {
    for (int k = 0; k < MAX_N; k++) {
        for (int i = 0; i < MAX_AB; i++) {
            for (int j = 0; j < MAX_AB; j++) {
                dp[k][i][j] = INF;
            }
        }
    }
    dp[0][0][0] = 0;

    int N, Ma, Mb; cin >> N >> Ma >> Mb;
    for (int i = 0; i < N; i++) {
        int a, b, c; cin >> a >> b >> c;
        for (int j = 0; j < MAX_AB; j++) {
            for (int k = 0; k < MAX_AB; k++) {
                if (dp[i][j][k] == INF) continue;
                dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
                dp[i+1][j+a][k+b] = min(dp[i+1][j+a][k+b],dp[i][j][k]+c);
            }
        }

        // cout << "#" << endl;
        // for (int j = 0; j <= 10; j++) {
        //     for (int k = 0; k <= 10; k++) {
        //         cout << dp[i][j][k] << " ";
        //     }
        //     cout << endl;
        // }
    }

    int ans = INF;
    int pos_a = Ma;
    int pos_b = Mb;
    while (pos_a < MAX_AB && pos_b < MAX_AB) {
        ans = min(ans, dp[N][pos_a][pos_b]);
        pos_a += Ma;
        pos_b += Mb;
    }

    if (ans != INF) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
