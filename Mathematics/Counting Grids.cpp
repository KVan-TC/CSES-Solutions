#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

const int M = 1e9 + 7;
const int inv4 = (M + 1) / 4;
 
ll n;
 
ll pw(ll x, ll n, ll q) {
    x %= q;
    ll a = 1;
    for (; n; x = x * x % q, n >>= 1)
        if (n & 1)
            a = a * x % q;
 
    return a;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n;

    ll q180 = (n * n + 1) / 2, q90 = (n * n + 3) / 4;

    ll ans = pw(2, n * n % (M - 1), M) + pw(2, q180 % (M - 1), M) + 2 * pw(2, q90 % (M - 1), M);

    cout << ans % M * inv4 % M << "\n";
    return 0;
}