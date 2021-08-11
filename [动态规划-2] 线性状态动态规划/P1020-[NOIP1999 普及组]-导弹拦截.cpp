#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 1;

int n, t, ans, arr[MAXN], dp[MAXN], f[MAXN];

int main() {
    while (~scanf("%d", &arr[++n]));
    for (int i = 1; i < n; i++) {
        dp[i] = 1;
        for (int j = t; j > 0; j--) {
            if (arr[i] <= arr[f[j]] && dp[f[j]] + 1 > dp[i]) {
                dp[i] = dp[f[j]] + 1;
                break;
            }
        }
        t = max(t, dp[i]);
        f[dp[i]] = i;
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
    ans = t = 0;
    for (int i = 1; i < n; i++) {
        dp[i] = 1;
        for (int j = t; j > 0; j--) {
            if (arr[i] > arr[f[j]] && dp[f[j]] + 1 > dp[i]) {
                dp[i] = dp[f[j]] + 1;
                break;
            }
        }
        t = max(t, dp[i]);
        f[dp[i]] = i;
        ans = max(ans, dp[i]);
    }
    printf("%d", ans);
    return 0;
}
