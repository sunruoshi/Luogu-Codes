#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1000;

int n, a[N], dp[N][N], ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int l = 1; l <= n; l++) {
        for (int i = 1; i + l <= 2 * n; i++) {
            int j = i + l;
            for (int k = i + 1; k < j; k++) {
                dp[i][j] = max(dp[i][j], a[i] * a[k] * a[j] + dp[i][k] + dp[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) ans = max(ans, dp[i][n + i]);
    cout << ans << endl;
    return 0;
}
