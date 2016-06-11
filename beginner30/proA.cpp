#include <iostream>
using namespace std;

int main(void) {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    if (A != C) {
        B *= C;
        D *= A;
    }

    if (B > D) {
        cout << "TAKAHASHI" << endl;
    } else if (B < D) {
        cout << "AOKI" << endl;
    } else {
        cout << "DRAW" << endl;
    }

    return 0;
}
