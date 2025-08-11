#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;

string S;
vector<string> v;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> S;
    sort(S.begin(), S.end());

    do {
        v.push_back(S);
    } while (next_permutation(S.begin(), S.end()));

    cout << v.size() << "\n";
    for (string s : v) 
        cout << s << "\n";
    return 0;
}
