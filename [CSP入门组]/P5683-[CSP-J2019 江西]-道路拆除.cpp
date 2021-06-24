#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3001, INF = 0x3f3f3f3f;

struct Node {
    int v, dis;
};

bool operator < (Node a, Node b) {
    return a.dis > b.dis;
}

vector<int> adj[MAXN];
int n, m, dis[MAXN], dis1[MAXN], dis2[MAXN];

void dijkstra(int s) {
    bool visited[MAXN];
    memset(visited, 0, sizeof(visited));
    fill(dis, dis + MAXN, INF);
    priority_queue<Node> q;
    dis[s] = 0;
    q.push(Node({s, 0}));
    while (!q.empty()) {
        int u = q.top().v;
        q.pop();
        if (visited[u]) continue;
        visited[u] = 1;
        for (int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j];
            if (!visited[v] && dis[u] + 1 < dis[v]) {
                dis[v] = dis[u] + 1;
                q.push(Node({v, dis[v]}));
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
    int s1, t1, s2, t2;
    scanf("%d %d %d %d", &s1, &t1, &s2, &t2);
    dijkstra(s1);
    copy(dis, dis + n + 1, dis1);
    dijkstra(s2);
    copy(dis, dis + n + 1, dis2);
    dijkstra(1);
    int ans = INF;
    for (int i = 1; i <= n; i++) {
        if (dis[i] + dis1[i] <= t1 && dis[i] + dis2[i] <= t2) {
            ans = min(ans, dis[i] + dis1[i] + dis2[i]);
        }
    }
    printf("%d", ans == INF ? -1 : m - ans);
    return 0;
}
