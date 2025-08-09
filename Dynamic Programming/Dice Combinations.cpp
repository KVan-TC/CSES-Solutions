#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e6+5, M = 1e9 + 7;
 
int n, dp[N];
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= min(i, 6); j++)
            dp[i] = (dp[i] + dp[i - j]) % M;
    cout << dp[n] << "\n";

    return 0;
}