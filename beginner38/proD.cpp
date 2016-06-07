#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

const int MAX_N = 1 << 17;
typedef pair<int, int> pii;
int n;
int dat[2*MAX_N - 1];           // Segment tree

bool comp(const pii& lhs, const pii& rhs) {
    if (lhs.first == rhs.first) {
        return lhs.second > rhs.second;
    }
    return lhs.first < rhs.first;
}

void init(int n_) {
    n = 1;
    while (n < n_) n *= 2;

    for (int i = 0; i < 2*n-1; i++) dat[i] = INT_MIN;
}

// k番目の値 [0, n-1] をaに更新
void update(int k, int a) {
    k += n-1;
    dat[k] = a;
    while (k > 0) {
        k = (k-1) / 2;
        dat[k] = max(dat[2*k + 1], dat[2*k + 2]);
    }
}

// [a, b) の最大値を求める
// query(a, b, 0, 0, n)
int query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return INT_MIN;

    if (a <= l && r <= b) return dat[k];
    else {
        int vl = query(a, b, k*2+1, l, (l+r)/2);
        int vr = query(a, b, k*2+2, (l+r)/2, r);
        return max(vl, vr);
    }
}

int main(void) {
    int N; cin >> N;
    vector<pii> boxes(N);
    vector<int> dp(N);
    fill(dp.begin(), dp.end(), 1);
    for (int i = 0; i < N; i++) {
        cin >> boxes[i].first >> boxes[i].second; // cin >> w >> h;
    }
    sort(boxes.begin(), boxes.end(), comp);

    init(int(1e5));
    int ans = -1;
    for (int i = 0; i < N; i++) {
        dp[i] = max(dp[i], query(0, boxes[i].second, 0, 0, n)+1);
        ans = max(ans, dp[i]);
        update(boxes[i].second, dp[i]);
    }

    cout << ans << endl;

    // for (int i = 0; i < N; i++) {
    //     cout << "w: " << boxes[i].first << " h: " << boxes[i].second << endl;
    // }
    // for (int i = 0; i < N; i++) {
    //     cout << "dp[" << i << "]: " << dp[i] << endl; 
    // }

    return 0;
}
