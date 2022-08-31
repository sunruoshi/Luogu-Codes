#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1000;

int n, a[N], f[N][N], ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int i = (n << 1) - 1; i >= 0; i--) {
        for (int j = i + 1; j <= (n << 1); j++) {
            for (int k = i + 1; k < j; k++) {
                f[i][j] = max(f[i][j], a[i] * a[k] * a[j] + f[i][k] + f[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) ans = max(ans, f[i][n + i]);
    cout << ans << endl;
    return 0;
}
