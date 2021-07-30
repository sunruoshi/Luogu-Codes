#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1501, INF = 0x3f3f3f3f;

struct Edge {
    int v, w;
    Edge(int _v, int _w) {
        v = _v;
        w = _w;
    }
};

int n, m, dis[MAXN];
vector<Edge> adj[MAXN];

int dfs(int u) {
    if (dis[u] > -INF) return dis[u];
    for (unsigned int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i].v;
        dis[u] = max(dis[u], dfs(v) + adj[u][i].w);
    }
    return dis[u];
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 2; i <= n; i++) {
        dis[i] = -INF;
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[v].push_back(Edge(u, w));
    }
    int ans = dfs(n);
    if (ans != -INF) printf("%d", ans);
    else printf("-1");
    return 0;
}
