#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 101, MOD = 1e6 + 7;

int n, m, a, dp[MAXN];

int main() {
    scanf("%d %d", &n, &m);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        for (int j = m; j >= 0; j--) {
            for (int k = 1; k <= min(j, a); k++) {
                dp[j] = (dp[j] + dp[j - k]) % MOD;
            }
        }
    }
    printf("%d", dp[m]);
    return 0;
}
