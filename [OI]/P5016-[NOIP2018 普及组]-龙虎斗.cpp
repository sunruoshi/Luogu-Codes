#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    long long n, m, p1, p2, s1, s2, sum = 0;
    scanf("%lld", &n);
    long long c[n + 1];
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &c[i]);
    }
    scanf("%lld %lld %lld %lld", &m, &p1, &s1, &s2);
    c[p1] += s1;
    for (int i = 1; i <= n; i++) {
        sum += c[i] * (m - i);
    }
    p2 = m + int(sum * 1.0 / s2 + 0.5 * (sum > 0 ? 1 : -1));
    printf("%lld", p2);
    return 0;
}
