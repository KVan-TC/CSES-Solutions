#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5+5;;
 
int n, m, ds[N], p[N];
bool used[N];
vector<int> ans, adj[N];
 
void dfs(int u) {
    for (int v : adj[u]) 
        if (v != p[u]) {
            p[v] = u;
            dfs(v);
        }
}
 
int find(int u) {
    return (!ds[u] ? u : ds[u] = find(ds[u]));
}
 
bool merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    if (ds[u] < ds[v]) swap(u, v);
    ds[v] += ds[u];
    ds[u] = v;
    return true;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> m;
 
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        if (!merge(u, v)) {
            dfs(u);
 
            int q = v;
            while (q) {
                ans.push_back(q);
                q = p[q];
            }
            ans.push_back(v);
 
            int k = ans.size();
            cout << k << "\n";
            for (int x : ans)
                cout << x << " ";
            cout << "\n";
            return 0;
        } else {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
 
    cout << "IMPOSSIBLE\n";
    return 0;
}