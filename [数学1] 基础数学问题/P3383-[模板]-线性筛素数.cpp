#include <cstdio>

const int MAXN = 1e8 + 1;

bool notPrime[MAXN];
int primes[MAXN], p;

void solve(int n) {
    for (int i = 2; i <= n; i++) {
        if (!notPrime[i]) primes[++p] = i;
        for (int j = 1; j <= p && i * primes[j] <= n; j++) {
            notPrime[i * primes[j]] = 1;
            if (i % primes[j] == 0) break;
        }
    }
}

int main() {
    int n, q, k;
    scanf("%d %d", &n, &q);
    solve(n);
    while (q--) {
        scanf("%d", &k);
        printf("%d\n", primes[k]);
    }
    return 0;
}
