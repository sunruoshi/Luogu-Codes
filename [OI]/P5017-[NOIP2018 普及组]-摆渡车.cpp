#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 501
#define MAXT 4000001
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

int n, m, a[MAXN], s[MAXT], q[MAXT];
long long dp[MAXT], sum, ans = INF;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        s[++a[i]]++;
        sum += a[i];
    }
    int max_t = *max_element(a + 1, a + n + 1);
    int l = 1, r = 1;
    for (int i = 1; i <= max_t + m; i++) {
        s[i] += s[i - 1];
        if (i > m) {
            int temp = i - m;
            while (l < r && (dp[temp] - dp[q[r]]) * (s[q[r]] - s[q[r - 1]]) <= (dp[q[r]] - dp[q[r - 1]]) * (s[temp] - s[q[r]])) r--;
            q[++r] = temp;
        }
        while (l < r && dp[q[l]] - i * s[q[l]] >= dp[q[l + 1]] - i * s[q[l + 1]]) l++;
        dp[i] = dp[q[l]] + i * (s[i] - s[q[l]]);
        if (i >= max_t) ans = min(ans, dp[i]);
    }
    printf("%lld", ans - sum);
    return 0;
}
