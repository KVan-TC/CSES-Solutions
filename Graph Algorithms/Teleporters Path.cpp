#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n, m, in[N], out[N];
vector<int> cyc, adj[N];

void fail() {
    cout << "IMPOSSIBLE\n";
    exit(0);
}

void dfs(int u) {
    while (!adj[u].empty()) {
        int v = adj[u].back(); adj[u].pop_back();
        dfs(v);
    }
    cyc.push_back(u);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;

        adj[u].push_back(v);
        out[u]++, in[v]++;
    }

    out[n]++, in[1]++;
    for (int i = 1; i <= n; i++)
        if (in[i] != out[i]) fail();

    dfs(1);
    if ((int)cyc.size() != m + 1) fail();

    reverse(cyc.begin(), cyc.end());
    for (int x : cyc)
        cout << x << " ";
    cout << "\n";
    return 0;
}