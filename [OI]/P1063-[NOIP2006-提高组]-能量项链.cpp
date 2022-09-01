#include <iostream>
#include <algorithm>
using namespace std;

const int N = 201;

int n, a[N], f[N][N], ans;

int DP(int l, int r) {
    if (f[l][r]) return f[l][r];
    if (r - l == 1) return 0;
    for (int k = l + 1; k < r; k++) {
        f[l][r] = max(f[l][r], DP(l, k) + DP(k, r) + a[l] * a[k] * a[r]);
    }
    return f[l][r];
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    /*
    for (int i = (n << 1) - 1; i >= 0; i--) {
        for (int j = i + 1; j <= (n << 1); j++) {
            for (int k = i + 1; k < j; k++) {
                f[i][j] = max(f[i][j], a[i] * a[k] * a[j] + f[i][k] + f[k][j]);
            }
        }
    }
    */
    for (int i = 1; i <= n; i++) ans = max(ans, DP(i, n + i));
    cout << ans << endl;
    return 0;
}
