#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000001, INF = 0x3f3f3f3f, MOD = 100003;

struct Node {
    int v, dis;
};

bool operator < (Node a, Node b) {
    return a.dis > b.dis;
}

vector<int> adj[MAXN];
int n, m, dis[MAXN], num[MAXN];
bool visited[MAXN];

void dijkstra(int s) {
    fill(dis, dis + MAXN, INF);
    priority_queue<Node> q;
    dis[s] = 0;
    num[s] = 1;
    q.push(Node({s, 0}));
    while (!q.empty()) {
        int u = q.top().v;
        q.pop();
        if (visited[u]) continue;
        visited[u] = 1;
        for (int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j];
            if (!visited[v]) {
                if (dis[u] + 1 < dis[v]) {
                    dis[v] = dis[u] + 1;
                    num[v] = num[u];
                    q.push(Node({v, dis[v]}));
                } else if (dis[u] + 1 == dis[v]) {
                    num[v] = (num[v] % MOD + num[u] % MOD) % MOD;
                }
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
    dijkstra(1);
    for (int i = 1; i <= n; i++) {
        printf("%d\n", num[i]);
    }
    return 0;
}

