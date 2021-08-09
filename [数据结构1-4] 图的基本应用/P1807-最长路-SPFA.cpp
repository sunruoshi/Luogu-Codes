#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 1501, INF = 0x3f3f3f3f;

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

int n, m, dis[MAXN];
vector<Edge> adj[MAXN];
bool inq[MAXN];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back(Edge(v, -w));
    }
    fill(dis, dis + MAXN, INF);
    dis[1] = 0;
    priority_queue<Node> q;
    q.push(Node(1, 0));
    inq[1] = 1;
    while (q.size()) {
        int u = q.top().v;
        q.pop();
        inq[u] = 0;
        for (Edge edge : adj[u]) {
            int v = edge.v, w = edge.w;
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                if (!inq[v]) {
                    q.push(Node(v, dis[v]));
                    inq[v] = 1;
                }
            }
        }
    }
    if (dis[n] == INF) printf("-1");
    else printf("%d", -dis[n]);
    return 0;
}
