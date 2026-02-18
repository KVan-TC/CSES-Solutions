#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int t;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        
        cout << (((a + b) % 3 != 0 || a > 2 * b || b > 2 * a) ? "NO" : "YES") << "\n";
    }

    return 0;
}