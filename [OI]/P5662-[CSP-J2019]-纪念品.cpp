#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1e4 + 1, INF = 0x3f3f3f3f;

int dp[MAXN], price[101][101];

int main() {
    // freopen("souvenir.in", "r", stdin);
    // freopen("souvenir.out", "w", stdout);
    int t, n, m, ans;
    scanf("%d %d %d", &t, &n, &m);
    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &price[i][j]);
        }
    }
    ans = m;
    for (int i = 1; i < t; i++) {
        fill(dp, dp + MAXN, -INF);
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
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}
