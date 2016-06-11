#include <iostream>
using namespace std;

int main(void) {
    int A, B, C; cin >> A >> B >> C;
    int ans = 0;
    ans += A*B*2;
    ans += B*C*2;
    ans += C*A*2;

    cout << ans << endl;

    return 0;
}
