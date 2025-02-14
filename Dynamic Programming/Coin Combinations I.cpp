#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1e6 + 5, MOD = 1e9 + 7;

int n, S, a[105], f[N];
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
	cin >> n >> S;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + n + 1);

    for (int j = 1; j <= S; j++) {
        ll s = 0;
        for (int i = 1; i <= n; i++)
            if (j >= a[i]) s += f[j - a[i]];
        
        f[j] = s % MOD;
    }

    cout << f[S] << "\n";
 
	return 0;
}