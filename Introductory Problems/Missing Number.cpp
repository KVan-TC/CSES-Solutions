#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n;
    int num = 0;
    for (int i = 1; i <= n; i++)
        num ^= i;
    for (int x; cin >> x; )
        num ^= x;
    cout << num << "\n";
    return 0;
}
