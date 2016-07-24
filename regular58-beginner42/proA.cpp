#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B, C; cin >> A >> B >> C;
    if ((A == 5 && B == 5 && C == 7) || \
        (A == 5 && B == 7 && C == 5) || \
        (A == 7 && B == 5 && C == 5))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
