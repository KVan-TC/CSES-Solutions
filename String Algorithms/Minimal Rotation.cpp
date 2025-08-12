#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
string S;
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> S;
    int n = S.size();
    S += S;

    int p = 0;
    for (int i = 1; i < n; ) {
        int k = 0;
        while (k < n && S[p + k] == S[i + k]) k++;
        if (S[p + k] <= S[i + k]) i += k + 1;
        else p = max(i, p + k + 1), i = p + 1;
    }

    string ans = S.substr(p, n);
    cout << ans << "\n";
    return 0;
}