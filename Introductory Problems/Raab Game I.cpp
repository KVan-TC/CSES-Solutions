#include <bits/stdc++.h>
using namespace std;

int T, x[105];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, a, b; cin >> n >> a >> b;
        if (a + b > n || ((a == 0 || b == 0) && a + b != 0)) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = 1; i <= n; i++)
            cout << i << " ";
        cout << "\n";
        for (int i = 1; i <= b; i++)
            cout << a + i << " ";
        for (int i = 1; i <= a; i++)
            cout << i << " ";
        for (int i = a + b + 1; i <= n; i++)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
