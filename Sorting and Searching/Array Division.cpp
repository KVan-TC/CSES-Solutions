#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int N = 2e5+5;
 
int n, k, a[N];
ll S;

bool check(ll x) {
    int cnt = 1;
    ll s = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > x) return false;
        if (s + a[i] > x)
            cnt++, s = a[i];
        else
            s += a[i];
    }
    return cnt <= k;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll l = 0, r = 1e18;
    while (l <= r) {
        ll m = (l + r) / 2;
        if (check(m)) r = m - 1;
        else l = m + 1;
    }

    cout << l << "\n";
    return 0;
}