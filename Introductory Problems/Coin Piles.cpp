#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> T;
    for (int a, b; cin >> a >> b; )
        cout << ((a + b) % 3 != 0 || a > 2 * b || b > 2 * a ? "NO\n" : "YES\n");
    return 0;
}
