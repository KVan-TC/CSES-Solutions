#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e6+5;
 
string S;
int pi[N];
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> S;
    int n = S.size();
 
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && S[i] != S[j]) j = pi[j - 1];
        if (S[i] == S[j]) j++;
        pi[i] = j;
    }
    
    vector<int> ans;
    for (int k = pi[n - 1]; k > 0; k = pi[k - 1])
        ans.push_back(k);
    
    sort(ans.begin(), ans.end());
    for (int x : ans)
        cout << x << " ";
    cout << "\n";
    return 0;
}