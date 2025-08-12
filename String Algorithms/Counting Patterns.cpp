#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;

const int N = 2e5+5;;

int Q, sz = 1, lst, len[N], cnt[N], lnk[N] = {-1}, nxt[N][26];
vector<int> st[N];
string S, T;
 
void add(char ch) {
    int c = ch - 'a';
    int v = sz++;
    cnt[v] = 1;
    len[v] = len[lst] + 1;
    int p = lst;

    while (p != -1 && !nxt[p][c])
        nxt[p][c] = v, p = lnk[p];

    if (p == -1)
        lnk[v] = 0;
    else {
        int q = nxt[p][c];
        if (len[p] + 1 == len[q])
            lnk[v] = q;
        else {
            int clone = sz++;
            len[clone] = len[p] + 1;
            for (int c = 0; c < 26; c++)
                nxt[clone][c] = nxt[q][c];
            lnk[clone] = lnk[q];
            while (p != -1 && nxt[p][c] == q)
                nxt[p][c] = clone, p = lnk[p];
            lnk[q] = lnk[v] = clone;
        }
    }
    lst = v;
}

void update() {
    for (int i = 0; i < sz; i++)
        st[len[i]].push_back(i);
    for (int i = sz - 1; i >= 0; i--)
        for (int v : st[i])
            if (lnk[v] != -1)
                cnt[lnk[v]] += cnt[v];
}

int query(string s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (!nxt[v][c]) return 0;
        else v = nxt[v][c];
    }
    return cnt[v];
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> S >> Q;

    for (char c : S)
        add(c);
    update();

    for (int q = 0; q < Q; q++) {
        cin >> T;
        cout << query(T) << "\n";
    }

    return 0;
}