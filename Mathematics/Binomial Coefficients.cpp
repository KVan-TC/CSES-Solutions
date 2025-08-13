#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
const int N = 1e6;
const int M = 1e9 + 7;

int T;
ll fact[N+1], inv[N+1];

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
    inv[n] = pw(fact[n], M - 2, M);
    for (int i = n - 1; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % M;
}
 
ll C(int n, int k) {
    return fact[n] * inv[k] % M * inv[n - k] % M; 
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    init(N);
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, k; cin >> n >> k;
        
        cout << C(n, k) << "\n";
    }
 
    return 0;
}
