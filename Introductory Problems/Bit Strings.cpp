#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int M = 1e9 + 7;
 
ll n;
 
ll pw(ll x, ll n) {
    ll a = 1; x %= M;
    for (; n; n >>= 1, x = x * x % M)
        if (n & 1)
            a = a * x % M;
    return a;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n;
 
    cout << pw(2, n) << "\n";

    return 0;
}