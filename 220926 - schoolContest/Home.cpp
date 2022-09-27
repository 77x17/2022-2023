#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
const int MAX_N = 100000 + 1;

struct DisjointSet {
    vector<int> par;

    DisjointSet(int n = 0) {par.assign(n + 1, -1);}

    void Init(int n) {par.assign(n + 1, -1);}

    int findRoot(int x) {return (par[x] > 0) ? (par[x] = findRoot(par[x])) : (x);}

    bool Connected(int x, int y) {return (findRoot(x) == findRoot(y));}

    void Union(int x, int y) {
        if ((x = findRoot(x)) == (y = findRoot(y))) return;

        if (par[x] > par[y]) swap(x, y);

        par[x] += par[y]; par[y] = x;
    }
} dsu;

struct Edge {
    int u, v, c;

    Edge(int _u = 0, int _v = 0, int _c = 0) {u = _u, v = _v, c = _c;}

    bool operator < (const Edge& x) const {return c < x.c;}
};

int n, m;

vector<Edge> adj;

void Input() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v, c; cin >> u >> v >> c;

        adj.push_back(Edge(u, v, c));
    }
}

bool Ok(int anchor) {
    dsu = DisjointSet(n); dsu.Init(n);

    for (int i = 0; i <= anchor; i++) dsu.Union(adj[i].u, adj[i].v);

    if (dsu.Connected(1, n)) return false;

    for (int i = anchor + 1; i < adj.size(); i++) if (dsu.Connected(1, adj[i].u) && dsu.Connected(adj[i].v, n)) return true;

    for (int i = anchor + 1; i < adj.size(); i++) if (dsu.Connected(1, adj[i].v) && dsu.Connected(adj[i].u, n)) return true;

    return false;
}

void Process() {
    sort(adj.begin(), adj.end());

    int l = 0, r = adj.size() - 1, result = -1;

    while (l <= r) {
        int mid = (l + r) >> 1;

        if (Ok(mid)) result = adj[mid].c, l = mid + 1;
        else r = mid - 1;
    }

    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    if (fopen("Home.inp", "r")) freopen("Home.inp", "r", stdin), freopen("Home.out", "w", stdout);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
