#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;

int n;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j < n; j++)
            cout << (i ^ j) << " ";
        cout << "\n";
    }

    return 0;
}
