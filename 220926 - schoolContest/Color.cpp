#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 100000 + 1;

int n, q;  vector<int> color;

void Input() {
    cin >> n >> q;  color.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) cin >> color[i];
}

struct DisjointSet {
    vector<int> par;

    DisjointSet(int n = 0) {par.assign(n + 1, -1);}

    int findRoot(int x) {
        return (par[x] > 0) ? (findRoot(par[x])) : (x);
    }

    void Union(int x, int y) {
        if ((x = findRoot(x)) == (y = findRoot(y))) return;

        if (par[x] > par[y]) swap(x, y);

        par[x] += par[y];  par[y] = x;
    }
} dsu;

vector<int> f;

void Update(int x, int y) {
    if (f[x] == -1 || x == y) return;

    if (f[y] != -1) dsu.Union(f[x], f[y]);

    color[dsu.findRoot(f[x])] = y;

    f[y] = dsu.findRoot(f[x]);

    f[x] = -1;
}

void Process() {
    dsu = DisjointSet(n);

    f.assign(MAX_N, -1);

    for (int i = 1; i <= n; i++) f[color[i]] = i;

    for (int i = 1; i <= n; i++) dsu.Union(i, f[color[i]]);

    while (q--) {
        int k; cin >> k;

        if (k == 1) {
            int x, y; cin >> x >> y;

            Update(x, y);
        } else {
            int x; cin >> x;

            cout << color[dsu.findRoot(x)] << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    if (fopen("Color.inp", "r")) freopen("Color.inp", "r", stdin), freopen("Color.out", "w", stdout);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
