#include <iostream>
#include <vector>
using namespace std;

int main(void) {

    int N, M; cin >> N >> M;
    int X, Y; cin >> X >> Y;
    vector<int> a(N), b(M);
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int j = 0; j < M; j++) cin >> b[j];

    int b_j = 0;
    int t = 0;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (a[i] >= t) {
            t = a[i]+X;
            while (b_j < M && b[b_j] < t) b_j++;
            if (b_j >= M) break;
            t = b[b_j]+Y;
            b_j++; cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
