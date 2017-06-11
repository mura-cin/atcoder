#include <iostream>
using namespace std;

int main(void) {

    int r, g, b; cin >> r >> g >> b;
    cout << ((r*100+g*10+b)%4 == 0 ? "YES" : "NO") << endl;

    return 0;
}
