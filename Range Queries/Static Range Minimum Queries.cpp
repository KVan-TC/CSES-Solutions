#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int N = 2e5+5;
 
int n, Q, a[N], st[20][N];
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> Q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        st[0][i] = a[i];
    }
 
    for (int j = 0; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) <= n; i++)
            st[j + 1][i] = min(st[j][i], st[j][i + (1 << j)]);
 
    for (int i = 0; i < Q; i++) {
        int l, r; cin >> l >> r;
        int k = __lg(r - l + 1);
 
        cout << min(st[k][l], st[k][r - (1 << k) + 1]) << "\n";
    }
    return 0;
}
