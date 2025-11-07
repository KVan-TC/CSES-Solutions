#include <bits/stdc++.h>
using namespace std;

int n;
bool b[20];

void print() {
    for (int i = n; i > 0; i--)
        cout << b[i];
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n;

    print();
    for (int mask = 1; mask < (1 << n); mask++) {
        int LSB = __builtin_ffs(mask);
        b[LSB] ^= 1;
        print();
    }
    return 0;
}
