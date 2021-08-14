#include <cstdio>
#include <queue>
using namespace std;

const int MAXN = 5001;

struct Edge {
    int u, v, w;
    Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
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

int n, m, num, ans;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    UnionFind uf(n);
    priority_queue<Edge> q;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        q.push(Edge(u, v, w));
    }
    while (num < n - 1 && q.size()) {
        Edge edge = q.top();
        q.pop();
        if (uf.Find(edge.u) != uf.Find(edge.v)) {
            uf.Union(edge.u, edge.v);
            ans += edge.w;
            num++;
        }
    }
    if (num != n - 1) printf("orz");
    else printf("%d", ans);
    return 0;
}
