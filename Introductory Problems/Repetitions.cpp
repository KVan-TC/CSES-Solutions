#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> s;
    
    int n = s.size(), ans = 1, cur = 1;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] != s[i]) cur = 0;
        cur++;
        ans = max(ans, cur);
    }
    cout << ans << "\n";

    return 0;
}
