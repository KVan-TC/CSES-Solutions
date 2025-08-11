#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;

const int M = 1e9 + 7;
 
int n;

ll pw(ll x, ll n, ll M) {
    ll a = 1;
    for (; n; x = x * x % M, n >>= 1)
        if (n & 1)
            a = a * x % M;
    return a;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n;
    cout << pw(2, n, M) << "\n";
    return 0;
}
