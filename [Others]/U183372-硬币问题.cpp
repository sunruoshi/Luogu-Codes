#include <cstdio>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;

int main() {
    int n, s;
    scanf("%d %d", &n, &s);
    int minf[s + 1], maxf[s + 1], v[n + 1];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
    }
    fill(minf + 1, minf + s + 1, INF);
    fill(maxf + 1, maxf + s + 1, -INF);
    minf[0] = maxf[0] = 0;
    for (int i = 1; i <= s; i++) {
        for (int j = 1; j <= n; j++) {
            if (i >= v[j]) {
                minf[i] = min(minf[i], minf[i - v[j]] + 1);
                maxf[i] = max(maxf[i], maxf[i - v[j]] + 1);
            }
        }
    }
    printf("%d\n%d", minf[s], maxf[s]);
    return 0;
}
