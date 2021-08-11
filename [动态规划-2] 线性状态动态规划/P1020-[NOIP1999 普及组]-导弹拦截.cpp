#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 1;

int n, ans1, ans2, arr[MAXN], dp[MAXN], f[MAXN];

int main() {
    while (~scanf("%d", &arr[++n]));
    for (int i = 1; i < n; i++) {
        dp[i] = 1;
        for (int j = ans1; j > 0; j--) {
            if (arr[i] <= arr[f[j]]) {
                dp[i] = max(dp[i], dp[f[j]] + 1);
                break;
            }
        }
        f[dp[i]] = i;
        ans1 = max(ans1, dp[i]);
    }
    for (int i = 1; i < n; i++) {
        dp[i] = 1;
        for (int j = ans2; j > 0; j--) {
            if (arr[i] > arr[f[j]]) {
                dp[i] = max(dp[i], dp[f[j]] + 1);
                break;
            }
        }
        f[dp[i]] = i;
        ans2 = max(ans2, dp[i]);
    }
    printf("%d\n%d", ans1, ans2);
    return 0;
}
