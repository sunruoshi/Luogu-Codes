#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

double x[16], y[16], f[16][35000];

double getDist(int a, int b) {
    return sqrt(pow(x[a] - x[b], 2) + pow(y[a] - y[b], 2));
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lf %lf", &x[i], &y[i]);
    }
    memset(f, 127, sizeof(f));
    for (int s = 1; s <= (1 << n) - 1; s++) {
        for (int i = 1; i <= n; i++) {
            if ((s & (1 << (i - 1))) == 0) continue;
            if (s == (1 << (i - 1))) {
                f[i][s] = 0;
                continue;
            }
            for (int j = 1; j <= n; j++) {
                if ((s & (1 << (j - 1))) == 0 || i == j) continue;
                f[i][s] = std::min(f[i][s], f[j][s - (1 << (i - 1))] + getDist(i, j));
            }
        }
    }
    double ans = -1;
    for (int i = 1; i <= n; i++) {
        double s = f[i][(1 << n) - 1] + getDist(i, 0);
        if (ans == -1 || ans > s) ans = s;
    }
    printf("%.2lf", ans);
    return 0;
}
