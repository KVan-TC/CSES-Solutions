#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1e6 + 5, MOD = 1e9 + 7;

int n;
ll f[N];
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
	cin >> n;
 
	f[0] = f[1] = 1, f[2] = 2, f[3] = 4, f[4] = 8, f[5] = 16;
	for (int i = 6; i <= n; i++)
		f[i] = (f[i - 1] + f[i - 2] + f[i - 3] + f[i - 4] + f[i - 5] + f[i - 6]) % MOD;
 
	cout << f[n] << "\n";
 
	return 0;
}