#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXT 4000001 + 100
using namespace std;

int cnt[MAXT], sum[MAXT], dp[MAXT];

int main() {
    int n, m, tmax = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int t;
        scanf("%d", &t);
        cnt[t]++;
        sum[t] += t;
        tmax = max(t, tmax);
    }
    for (int i = 1; i <= tmax + m; i++) {
        cnt[i] += cnt[i - 1];
        sum[i] += sum[i - 1];
    }
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < m; i++) {
        dp[i] = cnt[i] * i - sum[i];
    }
    for (int i = m; i < tmax + m; i++) {
        if (cnt[i] == cnt[i - m]) {
            dp[i] = dp[i - m];
            continue;
        }
        for (int j = max(0, i - (m << 1) + 1); j <= max(0, i - m); j++) {
            dp[i] = min(dp[i], dp[j] + (cnt[i] - cnt[j]) * i - (sum[i] - sum[j]));
        }
    }
    printf("%d", *min_element(dp + tmax, dp + tmax + m));
    return 0;
}
