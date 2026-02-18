#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
bool bit[105];

void print() {
    for (int i = n; i >= 1; i--)
        cout << bit[i];
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    
    for (int mask = 0; mask < (1 << n); mask++) {
        int LSB = __builtin_ffs(mask);

        bit[LSB] ^= 1;
        print();
    }

    return 0;
}