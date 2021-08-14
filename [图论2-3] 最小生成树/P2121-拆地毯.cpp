#include <cstdio>
#include <queue>
using namespace std;

const int MAXN = 1e5 + 1;

struct Edge {
    int u, v, w;
    Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
    bool operator < (const Edge &a) const {
        return w < a.w;
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

int n, m, k, num, ans;

int main() {
    scanf("%d %d %d", &n, &m, &k);
    UnionFind uf(n);
    priority_queue<Edge> q;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        q.push(Edge(u, v, w));
    }
    while (num < k) {
        Edge edge = q.top();
        q.pop();
        if (uf.Find(edge.u) != uf.Find(edge.v)) {
            uf.Union(edge.u, edge.v);
            ans += edge.w;
            num++;
        }
    }
    printf("%d", ans);
    return 0;
}
