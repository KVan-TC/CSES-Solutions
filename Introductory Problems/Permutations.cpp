#include <bits/stdc++.h>
using namespace std;
 
int n;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n;
    if (n == 2 || n == 3) return cout << "NO SOLUTION\n", 0;
    for (int i = 2; i <= n; i += 2)
        cout << i << " ";
    for (int i = 1; i <= n; i += 2)
        cout << i << " ";
    return 0;
}
