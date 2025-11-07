#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
 
int n, m, adj[N];

int find(int u) {
    return (adj[u] < 0) ? u : adj[u] = find(adj[u]);
}

void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u != v) {
        if (adj[u] < adj[v]) swap(u, v);
        adj[v] += adj[u]; adj[u] = v;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> m;
    for (int i = 1; i <= n; i++) adj[i] = -1;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        merge(u, v);
    }
 
    vector<int> ans;
    for (int i = 1; i <= n; i++)
        if (find(i) == i)
            ans.push_back(i);

    int k = ans.size() - 1;
    cout << k << "\n";
    for (int i = 0; i < k; i++)
        cout << ans[i] << " " << ans[i + 1] << "\n";
    return 0;
}
