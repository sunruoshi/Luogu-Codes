#include <iostream>
using namespace std;

const int N = 1000001, MOD = 10000;

int n, f[N];

int main() {
    f[1] = 1;
    f[2] = 2;
    f[3] = 5;
    cin >> n;
    for (int i = 4; i <= n; i++) {
        f[i] = (f[i - 1] << 1) % MOD + f[i - 3] % MOD;
        f[i] %= MOD;
    }
    cout << f[n];
    return 0;
}
