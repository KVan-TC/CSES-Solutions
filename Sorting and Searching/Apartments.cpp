#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

int n, m, k, a[N], b[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    
    sort(a, a + n);
    sort(b, b + m);

    int ans = 0;
    for (int i = 0, j = 0; i < n && j < m; i++) {
        while (j < m && a[i] - b[j] > k) j++;
        
        if (abs(a[i] - b[j]) <= k)
            ans++, j++;
    }

    cout << ans << "\n";
    return 0;
}