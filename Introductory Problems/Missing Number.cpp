#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int n;
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n;

    ll num = 0;
    for (int i = 1; i <= n; i++)
        num ^= i;
    for (int i = 1; i < n; i++) {
        int x; cin >> x;
        num ^= x;
    }
    cout << num << "\n";

    return 0;
}