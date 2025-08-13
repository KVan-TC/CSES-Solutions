#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
const int N = 1e6;
const int M = 1e9 + 7;

int n;
ll f[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    f[2] = 1;
    for (int i = 3; i <= n; i++)
        f[i] = (i - 1) * (f[i - 1] + f[i - 2]) % M;

    cout << f[n] << "\n"; 
    return 0;
}
