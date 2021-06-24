#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10001, INF = pow(2, 31) - 1;

struct Edge {
    int v, w;
};

vector<Edge> adj[MAXN];
int n, m, s, dis[MAXN];
bool visited[MAXN];

void dijkstra(int s) {
    fill(dis, dis + MAXN, INF);
    dis[s] = 0;
    for (int i = 1; i <= n; i++) {
        int u = -1, MIN = INF;
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && dis[j] < MIN) {
                u = j;
                MIN = dis[j];
            }
        }
        if (u == -1) return;
        visited[u] = 1;
        for (int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j].v;
            if (!visited[v] && dis[u] + adj[u][j].w < dis[v]) {
                dis[v] = dis[u] + adj[u][j].w;
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back(Edge({v, w}));
    }
    dijkstra(s);
    for (int i = 1; i <= n; i++) {
        printf("%d ", dis[i]);
    }
    return 0;
}
