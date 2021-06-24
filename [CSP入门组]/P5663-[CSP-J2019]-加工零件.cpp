#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001, INF = 0x3f3f3f3f;

struct Node {
    int v, dis;
};

bool operator < (Node a, Node b) {
    return a.dis > b.dis;
}

vector<int> adj[MAXN];
int n, m, q, dis[MAXN][2];
bool visited[MAXN][2];

void dijkstra(int s) {
    fill(dis[0], dis[0] + MAXN * 2, INF);
    priority_queue<Node> q;
    dis[s][0] = 0;
    q.push(Node({s, 0}));
    while (!q.empty()) {
        int u = q.top().v;
        q.pop();
        for (int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j];
            if (dis[u][1] + 1 < dis[v][0]) {
                dis[v][0] = dis[u][1] + 1;
                if (!visited[v][0]) {
                    visited[v][0] = 1;
                    q.push(Node({v, dis[v][0]}));
                }
            }
            if (dis[u][0] + 1 < dis[v][1]) {
                dis[v][1] = dis[u][0] + 1;
                if (!visited[v][1]) {
                    visited[v][1] = 1;
                    q.push(Node({v, dis[v][1]}));
                }
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dijkstra(1);
    while (q--) {
        int a, L;
        scanf("%d %d", &a, &L);
        if (dis[a][L % 2] <= L) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
