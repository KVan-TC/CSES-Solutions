#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;

string S;
int f[26];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> S;

    for (char ch : S) f[ch - 'A']++;

    int c = -1;
    for (int i = 0; i < 26; i++)
        if (f[i] & 1) {
            if (c != -1) return cout << "NO SOLUTION\n", 0;
            c = i;
        }

    string half = "";
    for (int i = 0; i < 26; i++)
        half.append(f[i] / 2, char(i + 'A'));

    cout << half;
    if (c != -1) cout << char(c + 'A');
    reverse(half.begin(), half.end());
    cout << half;
    return 0;
}
