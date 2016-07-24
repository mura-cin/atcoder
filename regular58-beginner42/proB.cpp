#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; string L;
    cin >> N >> L;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    sort(S.begin(), S.end());
    string ret = "";
    for (int i = 0; i < N; i++) ret += S[i];

    cout << ret << endl;

    return 0;
}
