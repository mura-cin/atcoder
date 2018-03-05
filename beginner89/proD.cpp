#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

typedef pair<int, int> pii;

int main(void) {

    int H, W, D; cin >> H >> W >> D;
    vector<pii> coords(H*W+1);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int A; cin >> A;
            coords[A] = pii(i, j);
        }
    }

    vector<int> dist(H*W+1);
    for (int i = 1; i <= H*W; i++) {
        if (i <= D) {
            dist[i] = 0;
        } else {
            pii Lc = coords[i-D];
            pii Rc = coords[i];
            dist[i] = dist[i-D] + abs(Lc.first-Rc.first) + abs(Lc.second-Rc.second);
        }
    }

    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        int L, R; cin >> L >> R;
        cout << dist[R] - dist[L] << endl;
    }
    return 0;
}
