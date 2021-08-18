#include <cstdio>
#include <cstring>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    int dp[n + 1][2][3];
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 1; j++) {
            for (int k = 0; k <= 2; k++) {
                dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][k]) % MOD;
            }
        }
        for (int k = 0; k <= 2; k++) {
            dp[i][1][0] = (dp[i][1][0] + dp[i - 1][0][k]) % MOD;
        }
        for (int j = 0; j <= 1; j++) {
            for (int k = 1; k <= 2; k++) {
                dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % MOD;
            }
        }
    }
    for (int j = 0; j <= 1; j++) {
        for (int k = 0; k <= 2; k++) {
            ans = (ans + dp[n][j][k]) % MOD;
        }
    }
    printf("%d", ans);
    return 0;
}
