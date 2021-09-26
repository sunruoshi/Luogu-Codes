#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 10001, INF = (unsigned) (1 << 31) - 1;

struct Edge {
    int v, w;
    Edge(int _v, int _w) : v(_v), w(_w) {}
};

vector<Edge> adj[MAXN];
int n, m, s, dis[MAXN];
bool visited[MAXN];

void dijkstra(int s) {
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    for (int i = 1; i <= n; i++) {
        int u = -1, MIN = 0x3f3f3f3f;
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && dis[j] < MIN) {
                u = j;
                MIN = dis[j];
            }
        }
        if (u == -1) return;
        visited[u] = 1;
        for (Edge edge : adj[u]) {
            int v = edge.v, w = edge.w;
            if (!visited[v] && dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back(Edge(v, w));
    }
    dijkstra(s);
    for (int i = 1; i <= n; i++) {
        if (dis[i] != 0x3f3f3f3f) printf("%d ", dis[i]);
        else printf("%d ", INF);
    }
    return 0;
}
