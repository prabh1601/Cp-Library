#include"bits/stdc++.h"
using namespace std;

#define int long long
#define pb push_back
#define all(v) begin(v), end(v)
#define sz(v) (int)v.size()
#define ff first
#define ss second
const int inf = 4e18;
const int N = 2e5 + 10;

int vis[N];
list < pair<int, int>> adjList[N];
int ti[N];
int cur = 1;

bool check(int nd, int par) {
    vis[nd] = 1;

    bool ans = true;
    bool did = false;
    for (auto &p : adjList[nd]) {
        if (p.ss) {
            did = true;
            if (vis[p.ff] == 1) return false;
            else if (!vis[p.ff]) ans &= check(p.ff, nd);
        }
    }

    vis[nd] = 2;
    if (did or nd != par) ti[nd] = cur++;
    else vis[nd] = 0;
    return ans;
}

void dfs(int nd) {
    vis[nd] = 2;

    for (auto &p : adjList[nd]) {
        if (!vis[p.ff])
            dfs(p.ff);
    }
    ti[nd] = cur++;
}

void testCase(int t, int t_c) {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> edges;
    int dir[n];
    for (int i = 0; i < m; i++) {
        int d, u, v; cin >> u >> v >> d;
        adjList[u].pb({v, d});
        if (!d) adjList[v].pb({u, d});
        edges.pb({u, v});
        dir[i] = d;
    }

    bool pos = true;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) pos &= check(i, i);
    }

    if (!pos) {cout << "NO\n"; return;}

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i);
    }

    cout << "YES\n";
    for (auto &p : edges) {
        int u = p.ff, v = p.ss;
        if (ti[u] < ti[v]) swap(u, v);
        cout << u << ' ' << v << '\n';
    }

    for (int i = 1; i <= n; i++) {
        vis[i] = ti[i] = 0;
        adjList[i].clear();
        cur = 1;
    }

}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t_c; cin >> t_c;
    for (int t = 1; t <= t_c; t++) {
        // cout << "Case #" << t << ": ";
        testCase(t, t_c);
    }
}
