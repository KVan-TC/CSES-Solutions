#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s;
    sort(s.begin(), s.end());

    vector<string> q;
    do {
        q.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << (int)q.size() << "\n";
    for (string s : q) cout << s << "\n";

    return 0;
}