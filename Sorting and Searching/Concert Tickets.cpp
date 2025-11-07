#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

int n, m, a[N], ds[N];

int find(int u) {
    if (u < 0) return -1;
    return (ds[u] == u ? u : ds[u] = find(ds[u]));
}

void remove(int u) {
    ds[u] = find(u - 1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> m;

    iota(ds, ds + n, 0);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    sort(a, a + n);

    for (int i = 0; i < m; i++) {
        int t; cin >> t;
        int pos = upper_bound(a, a + n, t) - a - 1;
        if (pos < 0) {
            cout << "-1\n";
            continue;
        }
        int p = find(pos);
        if (p < 0)
            cout << "-1\n";
        else {
            cout << a[p] << "\n";
            remove(p);
        }
    }
    return 0;
}