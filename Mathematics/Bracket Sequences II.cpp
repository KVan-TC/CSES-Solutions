#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
const int N = 1e6+5;
const int M = 1e9 + 7;
 
int n;
ll fact[N];
string S;

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

ll C(int n, int k) {
    return fact[n] * pw(fact[k] * fact[n - k], M - 2, M) % M;
}

int sol() {
    if (n & 1) return 0;

    int k = S.size(), d = 0;
    for (char c : S) {
        if (c == '(') d++;
        else d--;

        if (d < 0) return 0;
    }

    if (d > n - k) return 0;

    int l = (n - k - d) / 2;
    ll ans = (C(n - k, l) - C(n - k, l + d + 1) + M) % M;

    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> S;
    init(n);

    cout << sol() << "\n";
    return 0;
}
