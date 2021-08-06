#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 151, INF = 0x3f3f3f3f;

struct Node {
    int x, y;
} node[MAXN];

double getDist(int i, int j) {
    int dx = node[i].x - node[j].x, dy = node[i].y - node[j].y;
    return sqrt(dx * dx + dy * dy);
}

int n;
double ans, rad1, rad2 = INF, dis[MAXN][MAXN], f[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &node[i].x, &node[i].y);
    }
    for (int i = 1; i <= n; i++) {
        char s[MAXN];
        scanf("%s", s + 1);
        for (int j = 1; j <= n; j++) {
            if (s[j] != '0') dis[i][j] = getDist(i, j);
            else if (i != j) dis[i][j] = INF;
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dis[i][k] + dis[k][j] < dis[i][j]) dis[i][j] = dis[i][k] + dis[k][j];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dis[i][j] != INF) f[i] = max(f[i], dis[i][j]);
            rad1 = max(rad1, f[i]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dis[i][j] == INF) rad2 = min(rad2, f[i] + getDist(i, j) + f[j]);
        }
    }
    ans = max(rad1, rad2);
    printf("%.6f", ans);
    return 0;
}
