#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 10001;

int n, ans, dp[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int u, len, temp = 0;
        scanf("%d %d", &u, &len);
        while (1) {
            int pre;
            scanf("%d", &pre);
            if (!pre) break;
            temp = max(temp, dp[pre]);
        }
        dp[u] = temp + len;
        ans = max(ans, dp[u]);
    }
    printf("%d", ans);
    return 0;
}
