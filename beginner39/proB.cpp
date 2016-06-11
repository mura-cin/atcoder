#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    int X; cin >> X;
    for (int i = 1; i <= int(sqrt(sqrt(X)))+1; i++) {
        if (i*i*i*i == X) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
