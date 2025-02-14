#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1e6 + 5, MOD = 1e9 + 7;

int n, S, a[105], f[N];
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
	cin >> n >> S;

    while (n--) {
        int x; cin >> x;
        for (int i = x; i <= S; i++)
            (f[i] += f[i - x]) %= MOD;
    }

    cout << f[S] << "\n";
 
	return 0;
}