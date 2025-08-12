#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
const int N = 1e6+5;
 
string S, T;
int LPS[N];
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> S >> T;
    int n = S.size(), m = T.size();
 
    for (int i = 1; i < m; i++) {
        int j = LPS[i - 1];
        while (j > 0 && T[i] != T[j]) j = LPS[j - 1];
        if (T[i] == T[j]) j++;
        LPS[i] = j;
    }
 
    int ans = 0;
    for (int i = 0, j = 0; i < n; ) {
        if (S[i] == T[j]) i++, j++;
        if (j == m) ans++, j = LPS[j - 1];
        else if (i < n && S[i] != T[j]) {
            if (j) j = LPS[j - 1];
            else i++;
        }
    }
 
    cout << ans << "\n";
    return 0;
}