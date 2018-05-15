#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {

    string S; cin >> S;
    int K; cin >> K;

    vector<string> substrs;
    for (int k = 1; k <= K; k++) {
        for (int i = 0; i < S.size()-k+1; i++) {
            string tS = S.substr(i, k);
            substrs.push_back(tS);
        }
    }
    sort(substrs.begin(), substrs.end());
    unique(substrs.begin(), substrs.end());

    cout << substrs[K-1] << endl;

    return 0;
}