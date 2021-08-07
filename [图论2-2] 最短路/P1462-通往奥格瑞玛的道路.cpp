#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 10001, INF = 0x3f3f3f3f;

struct Node {
    int v, dis;
    Node(int _v, int _dis) : v(_v), dis(_dis) {}
    bool operator < (const Node &a) const {
        return dis > a.dis;
    }
};

struct Edge {
    int v, w;
    Edge(int _v, int _w) : v(_v), w(_w) {}
};

int n, m, b, ans, dis[MAXN], fee[MAXN], f[MAXN]; 
vector<Edge> adj[MAXN];
bool visited[MAXN];

bool dijkstra(int x) {
    memset(visited, 0, sizeof(visited));
    fill(dis, dis + MAXN, INF);
    dis[1] = 0;
    priority_queue<Node> q;
    q.push(Node(1, 0));
    while (q.size()) {
        int u = q.top().v;
        q.pop();
        if (visited[u]) continue;
        visited[u] = 1;
        for (Edge edge : adj[u]) {
            int v = edge.v, w = edge.w;
            if (visited[v] || fee[v] > x) continue;
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                q.push(Node(v, dis[v]));
            }
        }
    }
    return dis[n] <= b ? 1 : 0;
}

int main() {
    scanf("%d %d %d", &n, &m, &b);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &fee[i]);
        f[i] = fee[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back(Edge(v, w));
        adj[v].push_back(Edge(u, w));
    }
    if (!dijkstra(INF)) {
        printf("AFK");
        return 0;
    }
    sort(f + 1, f + n + 1);
    int left = 1, right = n;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (dijkstra(f[mid])) {
            ans = f[mid];
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    printf("%d", ans);
    return 0;
}
