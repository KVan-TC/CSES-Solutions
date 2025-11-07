#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

int n, X, a[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> X;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    sort(a, a + n);

    int ans = 0;
    for (int i = 0, j = n - 1; i <= j; j--) {
        if (a[i] + a[j] <= X) i++;
        ans++;
    }

    cout << ans << "\n";
    return 0;
}