#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    for (int i = 0; i < T; i++) {
        int x1, y1, x2, y2, x3, y3; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        
        ll s = (x3 - x1) * (y2 - y1) - (y3 - y1) * (x2 - x1);

        if (s == 0)
            cout << "TOUCH\n";
        else if (s > 0)
            cout << "RIGHT\n";
        else
            cout << "LEFT\n";
    }

    return 0;
}
