#include <iostream>
#include <map>
using namespace std;

typedef long long ll;

int main(void) {

    int N; cin >> N;
    ll words[5];
    for (int i = 0; i < 5; i++) words[i] = 0;

    for (int i = 0; i < N; i++) {
        string S; cin >> S;
        char c = S[0];
        switch (c) {
            case 'M':
                words[0]++; break;
            case 'A':
                words[1]++; break;
            case 'R':
                words[2]++; break;
            case 'C':
                words[3]++; break;
            case 'H':
                words[4]++; break;
        }
    }

    ll ans = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = i+1; j < 5; j++) {
            for (int k = j+1; k < 5; k++) {
                ans += words[i]*words[j]*words[k];
            }
        }
    }

    cout << ans << endl;

    return 0;
}