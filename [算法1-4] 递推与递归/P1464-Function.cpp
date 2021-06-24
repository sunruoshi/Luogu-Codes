#include <cstdio>

long long res[22][22][22];

long long w(long long a, long long b, long long c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    else if (res[a][b][c]) return res[a][b][c];
    else if (a > 20 || b > 20 || c > 20) res[a][b][c] = w(20, 20, 20);
    else if (a < b && b < c) res[a][b][c] =  w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    else res[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    return res[a][b][c];
}

int main() {
    long long a, b, c;
    while (scanf("%lld %lld %lld", &a, &b, &c)) {
        if (a == -1 && b == -1 && c == -1) return 0;
        printf("w(%lld, %lld, %lld) = ", a, b, c);
        if (a > 20) a = 21;
        if (b > 20) b = 21;
        if (c > 20) c = 21;
        printf("%lld\n", w(a, b, c));
    }
    return 0;
}
