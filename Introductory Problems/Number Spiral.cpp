#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
int T;

ll sol(ll x, ll y) {
    ll m = max(x, y), r = (m - 1) * (m - 1);
    if (m & 1) return r + y + m - x;
    else return r + x + m - y;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> T;
    for (int x, y; cin >> x >> y; ) {
        cout << sol(x, y) << "\n";
    }
    return 0;
}
