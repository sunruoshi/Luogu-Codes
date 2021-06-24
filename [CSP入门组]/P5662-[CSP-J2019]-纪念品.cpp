#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[10001], price[101][101];

int main() {
    int t, n, m, ans;
    scanf("%d %d %d", &t, &n, &m);
    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &price[i][j]);
        }
    }
    ans = m;
    for (int i = 1; i < t; i++) {
        memset(dp, -10000, sizeof(dp));
        dp[ans] = ans;
        for (int j = 1; j <= n; j++) {
            for (int k = ans; k >= price[i][j]; k--) {
                dp[k - price[i][j]] = max(dp[k - price[i][j]], dp[k] + price[i + 1][j] - price[i][j]);
            }
        }
        for (int j = 0; j <= ans; j++) {
            ans = max(ans, dp[j]);
        }
    }
    printf("%d", ans);
    return 0;
}
