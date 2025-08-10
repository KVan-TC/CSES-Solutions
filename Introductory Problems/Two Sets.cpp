#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n;
    if (n % 4 != 0 && n % 4 != 3) return cout << "NO\n", 0;
    cout << "YES\n";
    ll S = n * (n + 1LL) / 4;
    vector<int> a, b;
    for (int i = n; i >= 1; i--)
        if (i <= S) {
            a.push_back(i);
            S -= i;
        } else
            b.push_back(i);

    cout << a.size() << "\n";
    for (int x : a) cout << x << " ";
    cout << "\n";

    cout << b.size() << "\n";
    for (int x : b) cout << x << " ";
    cout << "\n";
    return 0;
}
