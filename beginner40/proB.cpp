#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (1LL << 60);

int main(void) {

    ll n; cin >> n;
    ll min_val = INF;
    for (ll i = 1; i <= n; i++) {
        for (ll j = i; i*j <= n; j++) {
            min_val = min(min_val, abs(i-j)+(n-i*j));
        }
    }

    cout << min_val << endl;

    return 0;
}
