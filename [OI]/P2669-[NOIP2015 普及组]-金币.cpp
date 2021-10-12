# include <cstdio>

int main() {
    int k, n, coin = 0;
    scanf("%d", &k);
    for (n = 1; k >= n; k -= n++) {
        coin += n * n;
    }
    printf("%d", coin + k * n);
    return 0;
}
