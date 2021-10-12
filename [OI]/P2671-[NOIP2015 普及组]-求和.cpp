#include <cstdio>
#define MAXN 100001
#define MOD 10007

int sum[MAXN][2], cnt[MAXN][2], color[MAXN], number[MAXN];

int main() {
    // freopen("sum.in", "r", stdin);
    // freopen("sum.out", "w", stdout);
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &number[i]);
        number[i] %= MOD;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &color[i]);
        cnt[color[i]][i & 1]++;
        sum[color[i]][i & 1] += number[i];
        sum[color[i]][i & 1] %= MOD;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += i * ((sum[color[i]][i & 1] + (cnt[color[i]][i & 1] - 2) % MOD * number[i] + MOD) % MOD);
        ans %= MOD;
    }
    printf("%d", ans);
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}
