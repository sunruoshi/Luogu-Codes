#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 100001, INF = 0x3f3f3f3f;

struct Edge {
    int v, w;
    Edge(int _v, int _w) {
        v = _v;
        w = _w;
    }
};

struct Node {
    int v, dis;
    Node(int _v, int _dis) {
        v = _v;
        dis = _dis;
    }
};

bool operator < (Node a, Node b) {
    return a.dis > b.dis;
}

vector<Edge> adj[MAXN];
int n, m, s, dis[MAXN];
bool visited[MAXN];

void dijkstra(int s) {
    fill(dis, dis + MAXN, INF);
    priority_queue<Node> q;
    dis[s] = 0;
    q.push(Node(s, 0));
    while (q.size()) {
        int u = q.top().v;
        q.pop();
        if (visited[u]) continue;
        visited[u] = 1;
        for (unsigned int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j].v;
            if (!visited[v] && dis[u] + adj[u][j].w < dis[v]) {
                dis[v] = dis[u] + adj[u][j].w;
                q.push(Node(v, dis[v]));
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
        printf("%d ", dis[i]);
    }
    return 0;
}
