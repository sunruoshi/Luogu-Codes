#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 3001, INF = 0x3f3f3f3f;

struct Node {
    int v, dis;
    Node(int _v, int _dis) : v(_v), dis(_dis) {}
    bool operator < (const Node &a) const {
        return dis > a.dis;
    }
};

int n, m, s1, t1, s2, t2, ans = INF, dis[MAXN], dis1[MAXN], dis2[MAXN];
vector<int> adj[MAXN];

void dijkstra(int s, int dis[]) {
    bool visited[MAXN];
    memset(visited, 0, sizeof(visited));
    fill(dis, dis + MAXN, INF);
    dis[s] = 0;
    priority_queue<Node> q;
    q.push(Node(s, 0));
    while (q.size()) {
        int u = q.top().v;
        q.pop();
        if (visited[u]) continue;
        visited[u] = 1;
        for (int v : adj[u]) {
            if (!visited[v] && dis[u] + 1 < dis[v]) {
                dis[v] = dis[u] + 1;
                q.push(Node(v, dis[v]));
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    scanf("%d %d %d %d", &s1, &t1, &s2, &t2);
    dijkstra(s1, dis1);
    dijkstra(s2, dis2);
    dijkstra(1, dis);
    for (int i = 1; i <= n; i++) {
        if (dis[i] + dis1[i] <= t1 && dis[i] + dis2[i] <= t2) {
            ans = min(ans, dis[i] + dis1[i] + dis2[i]);
        }
    }
    printf("%d", ans == INF ? -1 : m - ans);
    return 0;
}
