#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

int q;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> q;
    while (q--) {
        ll k; cin >> k; 
        k--;

        int len = 1;
        ll p = 1;
        while (k >= 9 * p * len) {
            k -= 9 * p * len;
            p *= 10;
            len++;
        }

        cout << to_string(p + k / len)[k % len] << "\n";
    }

    return 0;
}
