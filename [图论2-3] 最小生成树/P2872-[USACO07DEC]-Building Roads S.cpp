#include <cstdio>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 1001;

struct Node {
    int x, y;
} node[MAXN];

struct Edge {
    int u, v;
    double w;
    Edge(int _u, int _v, double _w) : u(_u), v(_v), w(_w) {}
    bool operator < (const Edge &a) const {
        return w > a.w;
    }
};

struct UnionFind {
    int fa[MAXN];
    UnionFind(int n) {
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
        }
    }
    int Find(int x) {
        if (x != fa[x]) fa[x] = Find(fa[x]);
        return fa[x];
    }
    void Union(int x, int y) {
        fa[Find(x)] = Find(y);
    }
};

double dist(Node a, Node b) {
    double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int n, m, num;
double ans;
bool e[MAXN][MAXN];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &node[i].x, &node[i].y);
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        e[u][v] = e[v][u] = 1;
    }
    priority_queue<Edge> q;
    for (int u = 1; u < n; u++) {
        for (int v = u + 1; v <= n; v++) {
            if (e[u][v]) q.push(Edge(u, v, 0));
            else q.push(Edge(u, v, dist(node[u], node[v])));
        }
    }
    UnionFind uf(n);
    while (num < n - 1) {
        Edge edge = q.top();
        q.pop();
        if (uf.Find(edge.u) != uf.Find(edge.v)) {
            uf.Union(edge.u, edge.v);
            ans += edge.w;
            num++;
        }
    }
    printf("%.2lf", ans);
    return 0;
}
