#include <bits/stdc++.h>
using namespace std;

const int INF = (1 << 21);

int main(void) {

    int N; cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    vector<int> dp(N);
    dp[0] = 0; dp[1] = abs(a[1]-a[0]);
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i-2]+abs(a[i]-a[i-2]), dp[i-1]+abs(a[i]-a[i-1]));
    }
    // for (int i = 0; i < N; i++) {
    //     cout << "dp[" << i << "]: " << dp[i] << endl;
    // }

    cout << dp[N-1] << endl;

    return 0;
}
