#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pll = pair<ll, ll>;

const int M = 1e9 + 7;
 
ll n;
 
pll f(ll n) {
    if (n == 0) return {0, 1};
    pll p = f(n / 2);
    ll a = p.first, b = p.second;

    ll c = a * ((2 * b % M - a + M) % M) % M;
    ll d = (a * a % M + b * b % M) % M;

    if (n % 2 == 0) 
        return {c, d};
    else 
        return {d, (c + d) % M};
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n;

    cout << f(n).first << "\n";
    return 0;
}