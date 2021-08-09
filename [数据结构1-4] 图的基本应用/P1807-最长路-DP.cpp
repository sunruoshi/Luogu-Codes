#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1501, INF = 0x3f3f3f3f;

struct Edge {
    int v, w;
    Edge(int _v, int _w) : v(_v), w(_w) {}
};

int n, m, dp[MAXN];
vector<Edge> adj[MAXN];
bool visited[MAXN];

int DP(int u) {
    if (visited[u]) return dp[u];
    visited[u] = 1;
    for (Edge edge : adj[u]) {
        int v = edge.v, w = edge.w;
        dp[u] = max(dp[u], DP(v) + w);
    }
    return dp[u];
}

int main() {
    scanf("%d %d", &n, &m);
    fill(dp, dp + MAXN, -INF);
    dp[n] = 0;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back(Edge(v, w));
    }
    int ans = DP(1);
    if (visited[n]) printf("%d", ans);
    else printf("-1");
    return 0;
}
