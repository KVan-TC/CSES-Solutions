#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
ll n;
 
ll Legendre(ll n, ll p) {
    ll a = 0;
    for (ll x = p; x <= n; x *= p)
        a += n / x;
    return a;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n;
 
    cout << Legendre(n, 5) << "\n";

    return 0;
}