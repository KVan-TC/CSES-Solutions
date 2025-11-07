#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
 
int n, Q, st[N][32];
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> Q;
 
    for (int i = 0; i < n; i++)
        cin >> st[i][0];
 
    for (int j = 0; (1 << j) < n; j++)
        for (int i = 0; i + (1 << j) < n; i++)
            st[i][j + 1] = min(st[i][j], st[i + (1 << j)][j]);
 
 
    for (int q = 0; q < Q; q++) {
        int l, r; cin >> l >> r;
        l--;
        int k = 31 - __builtin_clz(r - l);
        cout << min(st[l][k], st[r - (1 << k)][k]) << "\n";
    }
    return 0;
}
