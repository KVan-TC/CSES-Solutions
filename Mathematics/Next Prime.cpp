#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
const int X = 1e6;

int T;
bool t[X+1];
vector<int> pr;
 
void init(int n) {
    for (int i = 2; i <= n; i++)
        t[i] = 1;
    for (int i = 2; i * i <= n; i++)
        if (t[i])
            for (int j = i * i; j <= n; j += i)
                t[j] = 0;
    for (int i = 2; i <= n; i++)
        if (t[i])
            pr.push_back(i);
}
 
bool is_prime(ll n) {
    for (int p : pr) {
        if (p >= n) break;
        if (n % p == 0) return false;
    }
    return true;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    init(X);
    cin >> T;
    for (int i = 0; i < T; i++) {
        ll x; cin >> x;
        
        x++;
        while(!is_prime(x)) x++;

        cout << x << "\n";
    }
 
    return 0;
}
