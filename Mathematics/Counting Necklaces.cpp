#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
const int N = 1e6;
const int M = 1e9 + 7;
 
int n, m, phi[N+1];
 
ll pw(ll x, ll n, ll q) {
    x %= q;
    ll a = 1;
    for (; n; x = x * x % q, n >>= 1)
        if (n & 1)
            a = a * x % q;
 
    return a;
}
 
void init(int n) {
    for (int i = 0; i <= n; i++)
        phi[i] = i;
    for (int i = 2; i <= n; i++)
        if (phi[i] == i)
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> m;
    init(n);

    ll ans = 0;
    for (int d = 1; d * d <= n; d++)
        if (n % d == 0) {
            ans = (ans + (phi[d] * pw(m, n / d, M) % M)) % M;

            if (d != n / d)
                ans = (ans + (phi[n / d] * pw(m, d, M) % M)) % M;
        }
 
    cout << ans * pw(n, M - 2, M) % M << "\n";
    return 0;
}
