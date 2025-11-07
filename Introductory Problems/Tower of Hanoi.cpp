#include <bits/stdc++.h>
using namespace std;

int n;
bool b[20];

void move(int a, int b, int h) {
    if (h == 1) {
        cout << a << " " << b << "\n";
        return;
    }

    int c = 6 - a - b;
    move(a, c, h - 1);
    cout << a << " " << b << "\n";
    move(c, b, h - 1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n;

    cout << (1 << n) - 1 << "\n";

    move(1, 3, n);
    return 0;
}
