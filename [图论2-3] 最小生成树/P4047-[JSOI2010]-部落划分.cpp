#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;

const int MAXN = 1000;

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
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
    }
    int Find(int x) {
        if (x != fa[x]) fa[x] = Find(fa[x]);
        return fa[x];
    }
    bool Union(int x, int y) {
        int xx = Find(x), yy = Find(y);
        if (xx == yy) return false;
        fa[xx] = yy;
        return true;
    }
};

double dist(Node a, Node b) {
    double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &node[i].x, &node[i].y);
    }
    priority_queue<Edge> q;
    for (int u = 0; u < n - 1; u++) {
        for (int v = u + 1; v < n; v++) {
            q.push(Edge(u, v, dist(node[u], node[v])));
        }
    }
    UnionFind uf(n);
    int num = 0;
    while (q.size()) {
        Edge edge = q.top();
        q.pop();
        if (uf.Union(edge.u, edge.v)) num++;
        if (num == n - k + 1) {
            printf("%.2lf", edge.w);
            break;
        }
    }
    return 0;
}
