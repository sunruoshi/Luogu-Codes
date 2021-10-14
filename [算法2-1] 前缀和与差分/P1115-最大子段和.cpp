#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int a[n], dp[n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    dp[0] = a[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(a[i], dp[i - 1] + a[i]);
    }
    printf("%d", *max_element(dp, dp + n));
    return 0;
}
