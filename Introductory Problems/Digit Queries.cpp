#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int Q;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        ll k; cin >> k;
        k--;

        int len = 1;
        ll l = 1, r = 9;
        while (k >= (r - l  + 1) * len) {
            k -= (r - l + 1) * len;
            l *= 10;
            r = r * 10 + 9;
            len++;
        }

        cout << to_string(l + k / len)[k % len] << "\n";
    }

    return 0;
}
