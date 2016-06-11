#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string S; cin >> S;
    string piano = "WBWBWWBWBWBW";
    string onkai[12] = {
        "Do", "Do+", "Re", "Re+",
        "Mi", "Fa", "Fa+", "So",
        "So+", "La", "La+", "Si"
    };

    bool flag = false;
    for (int i = 0; i < 12; i++) {
        if (piano[i] == 'B') continue;
        for (int j = 0; j < S.size(); j++) {
            if (S[j] == piano[(i+j)%12]) {
                flag = true;
            } else {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << onkai[i] << endl;
            break;
        }
    }

    return 0;
}
