#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001, INF = 0x3f3f3f3f;

struct Edge {
    int v, w;
};

vector<Edge> adj[MAXN];
int n, m, s, dis[MAXN], num[MAXN];
bool inq[MAXN];

bool SPFA(int s) {
    fill(dis, dis + MAXN, INF);
    priority_queue<int> q;
    q.push(s);
    inq[s] = 1;
    num[s]++;
    dis[s] = 0;
    while (!q.empty()) {
        int u = q.top();
        q.pop();
        inq[u] = 0;
        for (int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j].v;
            if (dis[u] + adj[u][j].w < dis[v]) {
                dis[v] = dis[u] + adj[u][j].w;
                if (!inq[v]) {
                    q.push(v);
                    inq[v] = 1;
                    num[v]++;
                    if (num[v] >= n) return false;
                }
            }
        }
    }
    return true;
}

int main() {
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back(Edge({v, w}));
    }
    SPFA(s);
    for (int i = 1; i <= n; i++) {
        printf("%d ", dis[i]);
    }
    return 0;
}
