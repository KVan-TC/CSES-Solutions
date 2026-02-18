#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;

void move(int n, int a, int b) {
    if (n == 1) {
        cout << a << " " << b << "\n";
        return;
    }

    int c = 6 - a - b;
    move(n - 1, a, c);
    move(1, a, b);
    move(n - 1, c, b);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    
    cout << (1 << n) - 1 << "\n";
    move(n, 1, 3);

    return 0;
}