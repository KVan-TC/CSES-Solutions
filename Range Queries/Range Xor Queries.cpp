#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
const int N = 2e5+5;;
 
int n, Q, p[N];
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> Q;
 
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        p[i] = p[i - 1] ^ x;
    }
 
    for (int q = 0; q < Q; q++) {
        int l, r; cin >> l >> r;
 
        cout << (p[r] ^ p[l - 1]) << "\n";
    }
    return 0;
}
