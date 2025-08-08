#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int M = 1e9 + 7;

int n;

ll pw(ll x, ll n, ll q) {
    ll a = 1;
    for (; n; n >>= 1, x = x * x % q)
        if (n & 1)
            a = a * x % q;

    return a;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a, b, c; cin >> a >> b >> c;
        cout << pw(a, pw(b, c % (M - 1), (M - 1)) % (M - 1), M) << "\n";
    }
    return 0;
}
