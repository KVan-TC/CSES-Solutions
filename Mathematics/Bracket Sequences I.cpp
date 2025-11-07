#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int N = 1e6+5;
const int M = 1e9 + 7;
 
int n;
ll fact[N];
 
void init(int n) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % M;
}
 
ll pw(ll x, ll n, ll q) {
    x %= q;
    ll a = 1;
    for (; n; x = x * x % q, n >>= 1)
        if (n & 1)
            a = a * x % q;
 
    return a;
}
 
ll C(int n) {
    return fact[2 * n] * pw(fact[n + 1] * fact[n], M - 2, M) % M;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n;
    init(n);
 
    cout << (n & 1 ? 0 : C(n / 2)) << "\n";
    return 0;
}
