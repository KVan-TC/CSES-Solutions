#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = 1e9 + 7;
const int inv2 = (M + 1) / 2;

ll n;

ll s(ll l, ll r) {
    return ((r - l + 1) % M) * ((l + r) % M) % M * inv2 % M;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    ll ans = 0, r;

    for (ll l = 1; l <= n; l = r + 1) {
        ll t = n / l;
        r = n / t;
        ans += t % M * s(l, r) % M;
        ans %= M;
    }
    cout << ans << "\n";
    return 0;
}
