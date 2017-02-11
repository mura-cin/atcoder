#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {

    int N, M; cin >> N >> M;
    vector<string> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];

    bool flag = false;
    for (int i = 0; i < N-M+1; i++) {
        for (int j = 0; j < N-M+1; j++) {
            flag = true;
            for (int k = 0; k < M; k++) {
                for (int l = 0; l < M; l++) {
                    if (A[i+k][j+l] != B[k][l]) flag = false;
                }
            }
            if (flag) break;
        }
        if (flag) break;
    }

    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
