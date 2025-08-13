#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
const int N = 2e6;
const int M = 1e9 + 7;

int n, m;
ll fact[N+1];

ll pw(ll x, ll n, ll q) {
    x %= M;
    ll a = 1;
    for (; n; n >>= 1, x = x * x % q)
        if (n & 1)
            a = a * x % q;
    return a;
}
void init(int n) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % M;
}
 
ll C(int n, int k) {
    return fact[n] * pw(fact[k] * fact[n - k], M - 2, M) % M; 
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    init(n + m - 1);
    
    cout << C(n + m - 1, m) << "\n";
    return 0;
}
