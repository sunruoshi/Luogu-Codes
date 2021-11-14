#include <cstdio>

int main() {
    freopen("candy.in", "r", stdin);
    freopen("candy.out", "w", stdout);

    int n, l, r;
    scanf("%d %d %d", &n, &l, &r);
    int mod = l % n;
    if (l + n - mod <= r) printf("%d", n - 1);
    else printf("%d", r % n);
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
