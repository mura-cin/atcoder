#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class ll_mod {
public:
    typedef long long ll;
    static const ll MOD = 1e9+7;
    ll x;

    ll_mod() {
        this->x = 0;
    }
    ll_mod(ll x) {
        this->x = x;
    }

    ll_mod operator + (const ll_mod rhs) {
        return ll_mod((this->x + rhs.x) % ll_mod::MOD);
    }
    ll_mod operator - (const ll_mod rhs) {
        return ll_mod((this->x + rhs.x) % ll_mod::MOD);
    }
    ll_mod operator * (const ll_mod rhs) {
        return ll_mod((this->x * rhs.x) % ll_mod::MOD);
    }
    ll_mod operator * (const ll x) {
        return ll_mod((this->x * x) % ll_mod::MOD);
    }
    ll_mod operator / (const ll_mod rhs) {
        return ll_mod((this->x / rhs.x) % ll_mod::MOD);
    }
};

// x^n % MOD
ll_mod pow_MOD(ll_mod x, ll n) {
    if (n == 0) return ll_mod(1);
    if (n == 1) return x;

    ll_mod ret = pow_MOD(x, n/2);
    if (n%2 == 0) {
        return ret*ret;
    } else {
        return ret*ret*x;
    }
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W, A, B; cin >> H >> W >> A >> B;
    vector<ll_mod> fact, inv_fact;
    fact.emplace_back(1); fact.emplace_back(1);
    for (ll i = 2; i < H+W; i++) {
        fact.emplace_back(fact[i-1]*i);
    }
    for (ll i = 0; i < H+W; i++) {
        inv_fact.emplace_back(pow_MOD(fact[i], ll_mod::MOD-2));
    }

    ll_mod ans(0);
    for (int i = B; i < W; i++) {
        ans = ans + fact[i+H-A-1]*inv_fact[i]*inv_fact[H-A-1] * \
            fact[A+W-i-2]*inv_fact[A-1]*inv_fact[W-i-1];
    }

    cout << ans.x << endl;

    return 0;
}
