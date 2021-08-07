#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 200, INF = 0x3f3f3f3f;

int n, m, q, k, t[MAXN], dis[MAXN][MAXN];

int main() {
    fill(dis[0], dis[0] + MAXN * MAXN, INF);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        dis[u][v] = dis[v][u] = w;
    }
    scanf("%d", &q);
    while (q--) {
        int u, v, ti;
        scanf("%d %d %d", &u, &v, &ti);
        while (k < n && t[k] <= ti) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dis[i][k] == INF || dis[k][j] == INF) continue;
                    if (dis[i][k] + dis[k][j] < dis[i][j]) {
                        dis[i][j] = dis[i][k] + dis[k][j];
                    }
                }
            }
            k++;
        }
        if (dis[u][v] == INF || t[u] > ti || t[v] > ti) printf("-1\n");
        else printf("%d\n", dis[u][v]);
    }
    return 0;
}
