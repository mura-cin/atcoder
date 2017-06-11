#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main(void) {

    int N; cin >> N;
    map<string, int> color;
    int up3200 = 0;

    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        if (a < 400) {
            color["gray"]++;
        } else if (a < 800){
            color["brown"]++;
        } else if (a < 1200) {
            color["green"]++;
        } else if (a < 1600) {
            color["lblue"]++;
        } else if (a < 2000) {
            color["blue"]++;
        } else if (a < 2400) {
            color["yellow"]++;
        } else if (a < 2800) {
            color["orange"]++;
        } else if (a < 3200) {
            color["red"]++;
        } else {
            up3200++;
        }
    }

    int min = color.size();
    cout << (min == 0 ? 1 : min) << " " << min+up3200 << endl;

    return 0;
}
