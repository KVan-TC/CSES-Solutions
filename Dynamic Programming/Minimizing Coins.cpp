#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1e6 + 5, oo = 2e9;

int n, S, f[N];
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
	cin >> n >> S;

    for (int i = 1; i <= S; i++)
        f[i] = oo;
 
	while (n--) {
        int x; cin >> x;
        for (int i = 0; i <= S - x; i++)
            if (f[i] != oo)
                f[i + x] = min(f[i + x], f[i] + 1);
    }

    cout << (f[S] == oo ? -1 : f[S]) << "\n";
 
	return 0;
}