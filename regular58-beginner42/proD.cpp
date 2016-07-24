#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;

// x^n % MOD
ll pow_MOD(ll x, ll n) {
    if (n == 0) return 1;
    if (n == 1) return x;

    ll ret = pow_MOD(x, n/2);
    if (n%2 == 0) {
        return (ret*ret) % MOD;
    } else {
        return (x * ((ret*ret)%MOD)) % MOD;
    }
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W, A, B; cin >> H >> W >> A >> B;
    vector<ll> fact(H+W), inv_fact(H+W);
    fact[0] = fact[1] = 1;
    for (ll i = 2; i < H+W; i++) {
        fact[i] = (fact[i-1]*i) % MOD;
    }
    for (ll i = 0; i < H+W; i++) {
        inv_fact[i] = pow_MOD(fact[i], MOD-2);
    }

    ll ans = 0;
    for (int i = B; i < W; i++) {
        ll tmp = (((fact[i+H-A-1]*inv_fact[i])%MOD) * inv_fact[H-A-1])%MOD;
        tmp = (tmp * ((((fact[A+W-i-2]*inv_fact[A-1])%MOD) * inv_fact[W-i-1])%MOD))%MOD;
        ans = (ans + tmp) % MOD;
    }

    cout << ans << endl;

    return 0;
}
