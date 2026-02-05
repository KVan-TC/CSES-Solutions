#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int N = 2e5+5;
 
int n, Q;
ll f[N];
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> Q;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        f[i] = f[i - 1] ^ x;
    }
 
    for (int i = 0; i < Q; i++) {
        int l, r; cin >> l >> r;
        cout << (f[r] ^ f[l - 1]) << "\n";
    }
    return 0;
}