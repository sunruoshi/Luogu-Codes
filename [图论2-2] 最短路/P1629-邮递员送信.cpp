#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define MAXN 1001
#define INF 0x3f3f3f3f
using namespace std;

struct Edge {
    int v, w;
    Edge(int _v, int _w) : v(_v), w(_w) {}
};

struct Node {
    int v, dis;
    Node(int _v, int _dis) : v(_v), dis(_dis) {}
    bool operator < (const Node &a) const {
        return dis > a.dis;
    }
};

vector<Edge> adj1[MAXN], adj2[MAXN];
int n, m, ans, dis1[MAXN], dis2[MAXN];

void dijkstra(int s, vector<Edge>* adj, int* dis) {
    bool visited[MAXN];
    memset(visited, 0, sizeof(visited));
    fill(dis, dis + MAXN, INF);
    priority_queue<Node> q;
    dis[s] = 0;
    q.push(Node(s, 0));
    while (q.size()) {
        int u = q.top().v;
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
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj1[u].push_back(Edge(v, w));
        adj2[v].push_back(Edge(u, w));
    }
    dijkstra(1, adj1, dis1);
    dijkstra(1, adj2, dis2);
    for (int i = 2; i <= n; i++) {
        ans += dis1[i] + dis2[i];
    }
    printf("%d", ans);
    return 0;
}
