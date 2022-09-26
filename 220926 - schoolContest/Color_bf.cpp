#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 77 * 17;

int n, q;  vector<int> arr;

void Input() {
    cin >> n >> q;  arr.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) cin >> arr[i];
}

void Update(int x, int y) {
    for (int i = 1; i <= n; i++) if (arr[i] == x) arr[i] = y;
}

void Process() {
    while (q--) {
        int k; cin >> k;

        if (k == 1) {
            int x, y; cin >> x >> y;

            Update(x, y);
        } else {
            int x; cin >> x;

            cout << arr[x] << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    if (fopen("Color.inp", "r")) freopen("Color.inp", "r", stdin), freopen("Color_bf.out", "w", stdout);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}

