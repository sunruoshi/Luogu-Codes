# include <cstdio>

int main() {
    // freopen("coin.in", "r", stdin);
    // freopen("coin.out", "w", stdout);
    int k, n, coin = 0;
    scanf("%d", &k);
    for (n = 1; k >= n; k -= n++) {
        coin += n * n;
    }
    printf("%d", coin + k * n);
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}
