#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int t;
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> t;
 
    while (t--) {
        ll x, y; cin >> x >> y;
        ll m = max(x, y), ans = (m - 1) * (m - 1);
        
        if (m & 1) ans += y + m - x;
        else ans += x + m - y;

        cout << ans << "\n";
    }
    return 0;
}