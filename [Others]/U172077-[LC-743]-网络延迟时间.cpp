#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;

struct Edge {
    int v, w;
    Edge(int _v, int _w) : v(_v), w(_w) {}
};

struct Node {
    int u, dis;
    Node(int _u, int _dis) : u(_u), dis(_dis) {}
    bool operator < (const Node &a) const {
        return dis > a.dis;
    }
};

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int dis[n + 1];
    bool visited[n + 1];
    vector<Edge> adj[n + 1];
    memset(visited, 0, sizeof(visited));
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back(Edge(v, w));
    }
    memset(dis, 0x3f, sizeof(dis));
    dis[k] = 0;
    priority_queue<Node> q;
    q.push(Node(k, 0));
    while (q.size()) {
        int u = q.top().u;
        q.pop();
        if (visited[u]) continue;
        visited[u] = 1;
        for (Edge edge : adj[u]) {
            int v = edge.v, w = edge.w;
            if (!visited[v] && dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                q.push(Node(v, dis[v]));
            }
        }
    }
    int ans = *max_element(dis + 1, dis + n + 1);
    if (ans == INF) printf("-1");
    else printf("%d", ans);
    return 0;
}
