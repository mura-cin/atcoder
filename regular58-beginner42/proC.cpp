#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;  cin >> N >> K;
    vector<int> D(K);
    for (int i = 0; i < K; i++) cin >> D[i];

    for (int i = N; i <= 10*N; i++) {
        int tmp = i;
        bool flag;
        while (tmp != 0) {
            flag = false;
            int d = tmp % 10;
            for (int j = 0; j < D.size(); j++) {
                if (D[j] == d) {
                    flag = true;
                    break;
                }
            }
            if (flag) break;
            tmp /= 10;
        }
        if (!flag) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
