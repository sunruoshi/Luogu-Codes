#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1001;

long long lose[MAXN], win[MAXN], use[MAXN], dp[MAXN];

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld %lld", &lose[i], &win[i], &use[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = x; j >= 0; j--) {
            if (j >= use[i]) dp[j] = max(dp[j] + lose[i], dp[j - use[i]] + win[i]);
            else dp[j] += lose[i];
        }
    }
    printf("%lld", 5 * dp[x]);
    return 0;
}
