#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MIN_N = 1000;
const int MAX_N = 10000;

int Rand(int l, int r) {
    int mod = (r - l + 1);

    return 1LL * rand() * rand() % mod + l;
}

void Input() {
    ofstream inp(((const string)"Color.inp").c_str());

    int t = Rand(1, 5); inp << t << '\n'; while (t--) {
        int n = Rand(MIN_N, MAX_N), q = Rand(MIN_N, MAX_N); inp << n << ' ' << q << '\n';

        for (int i = 1; i <= n; i++) inp << Rand(1, MAX_N) << " \n"[i == n];

        while (q--) {
            int k = Rand(1, 2); inp << k << ' ';

            if (k == 1) inp << Rand(1, MAX_N) << ' ' << Rand(1, MAX_N) << '\n';
            else inp << Rand(1, n) << '\n';
        }
    }

    inp.close();
}

void Process() {
    system("Color.exe");  system("Color_bf.exe");

    if (system("fc Color.out Color_bf.out")) {cout << "wrongAnswer\n"; exit(0);}

    cout << "accept\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);  srand(time(NULL));

    for (int i = 1; i <= 100; i++) {
        cerr << '\n' << "Test: " << i << '\n';

        Input();

        Process();
    }

    return 0;
}
