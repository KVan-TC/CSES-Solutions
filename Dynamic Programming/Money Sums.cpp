#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int X = 1e5+5;

int n;
bool f[X];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    f[0] = 1;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        for (int s = X; s >= x; s-- )
            f[s] |= f[s - x];
    }
    
    vector<int> v;
    for (int s = 1; s <= X; s++)
        if (f[s]) v.push_back(s);

    cout << v.size() << "\n";
    for (int x : v)
        cout << x << " ";
    return 0;
}
