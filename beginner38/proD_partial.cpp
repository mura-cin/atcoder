#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef pair<int, int> pii;

int main(void) {
    int N; cin >> N;
    vector<pii> boxes(N);
    vector<int> dp(N);
    fill(dp.begin(), dp.end(), 1);
    for (int i = 0; i < N; i++) {
        cin >> boxes[i].first >> boxes[i].second; // cin >> w >> h;
    }
    sort(boxes.begin(), boxes.end());

    int ans = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (boxes[i].first > boxes[j].first && \
                boxes[i].second > boxes[j].second) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;

    // for (int i = 0; i < N; i++) {
    //     cout << "h: " << boxes[i].first << " w: " << boxes[i].second << endl;
    // }
    // for (int i = 0; i < N; i++) {
    //     cout << "dp[" << i << "]: " << dp[i] << endl; 
    // }

    return 0;
}
