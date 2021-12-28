#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 1e6 + 1;

bool notPrime[MAXN];
int primes[MAXN], ans, p;

void solve() {
    for (int i = 2; i < 47000; i++) {
        if (!notPrime[i]) primes[++p] = i;
        for (int j = 1; j <= p && i * primes[j] < 47000; j++) {
            notPrime[i * primes[j]] = 1;
            if (i % primes[j] == 0) break;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    solve();
    int l, r;
    cin >> l >> r;
    if (l == 1) l = 2;
    memset(notPrime, 0, sizeof(notPrime));
    for (int i = 1; i <= p; i++) {
        long long start = max((l + primes[i] - 1) / primes[i] * primes[i], primes[i] << 1);
        for (long long j = start; j <= r; j += primes[i]) {
            notPrime[j - l + 1] = 1;
        }
    }
    for (int i = 1; i <= r - l + 1; i++) {
        if (!notPrime[i]) ans++;
    }
    cout << ans;
    return 0;
}
