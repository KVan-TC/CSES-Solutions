#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n;
    
    int ans = 0;
    for (int p = 5; n >= p; n /= p)
        ans += n / p;
    cout << ans << "\n";
    return 0;
}
