#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int N = 2e5+5;
 
int n;
ll p[N];
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n;

    ll s = 0, ans = -1e18;
    for (int i = 1; i <= n; i++) {
        ll x; cin >> x;
        s = max(s + x, x);
        ans = max(ans, s);
    }
    cout << ans << "\n";
    return 0;
}