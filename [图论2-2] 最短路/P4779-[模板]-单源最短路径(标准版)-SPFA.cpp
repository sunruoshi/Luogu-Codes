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
    bool operator < (const Node &a) const {
        return dis > a.dis;
    }
};

vector<Edge> adj[MAXN];
int n, m, s, dis[MAXN], num[MAXN];
bool inq[MAXN];

bool SPFA(int s) {
    fill(dis, dis + MAXN, INF);
    priority_queue<Node> q;
    q.push(Node(s, 0));
    inq[s] = 1;
    num[s]++;
    dis[s] = 0;
    while (!q.empty()) {
        int u = q.top().v;
        q.pop();
        inq[u] = 0;
        for (unsigned int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].v, w = adj[u][i].w;
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                if (!inq[v]) {
                    q.push(Node(v, dis[v]));
                    inq[v] = 1;
                    num[v]++;
                    if (num[v] >= n) return 0;
                }
            }
        }
    }
    return 1;
}

int main() {
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back(Edge(v, w));
    }
    SPFA(s);
    for (int i = 1; i <= n; i++) {
        printf("%d ", dis[i]);
    }
    return 0;
}
