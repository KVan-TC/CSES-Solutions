#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll K;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> K;
    for (ll k = 1; k <= K; k++)
        cout << (1LL + (k - 1) * (k - 2) / 2) * (k - 1) * (k + 4) << "\n";
    return 0;
}
// k^2(k^2+1)/2 - 4(k-1)(k-2) = (1+(k-1)(k-2)/2)(k-1)(k+4)