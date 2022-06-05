#include <cstdio>
#include <cstring>

const int MOD = 1e9 + 7;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);
        char s[n + 2], t[m + 2];
        scanf("%s %s", s + 1, t + 1);
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '-') cnt++;
        }
        if (n - 2 * cnt != m) {
            printf("0\n");
            continue;
        }
        int dp[n + 1][cnt + 1][cnt + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;
        int len = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '-') len--;
            else len++;
            for (int l = 0; l <= cnt; l++) {
                for (int r = 0; r <= cnt; r++) {
                    if (s[i] == '-') {
                        dp[i][l][r] = (dp[i - 1][l + 1][r] + dp[i - 1][l][r + 1]) % MOD;
                    } else {
                        if (r) dp[i][l][r] = dp[i - 1][l][r - 1];
                        if (!r && s[i] == t[len - l]) dp[i][l][r] = dp[i - 1][l][r];
                        if (len == l) dp[i][l][r] = (dp[i][l][r] + dp[i - 1][l - 1][r]) % MOD;
                    }
                }
            }
        }
        printf("%d\n", dp[n][0][0]);
    }
    return 0;
}
