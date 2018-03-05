#include <iostream>
#include <map>
using namespace std;

int main(void) {

    int N; cin >> N;
    bool is_Y = false; 
    for (int i = 0; i < N; i++) {
        char S; cin >> S;
        if (S == 'Y') is_Y = true;
    }

    cout << (is_Y ? "Four" : "Three") << endl;

    return 0;
}