#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;

const int N = 1e6+5;

string S;
int p[2 * N];
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> S;
    string T = "@#";
    for (char c : S) {
        T += c;
        T += '#';
    }
    T += '$';
    int n = T.size();
    
    for (int i = 0, ct = 0, r = 0; i < n; i++) {
        int mir = 2 * ct - i;
        if (i < r) p[i] = min(r - i, p[mir]);
        while (T[i + p[i] + 1] == T[i - p[i] - 1]) p[i]++;
        if (i + p[i] > r)
            ct = i, r = i + p[i];
    }

    int len = 0, ct = 0;
    for (int i = 1; i < n - 1; i++)
        if (p[i] > len) len = p[i], ct = i;
    
    int st = (ct - len) / 2;

    cout << S.substr(st, len) << "\n";
    return 0;
}