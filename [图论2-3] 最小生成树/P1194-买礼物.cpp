#include <cstdio>
#include <queue>
using namespace std;

const int MAXN = 501;

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

int a, b, num, ans;

int main() {
    scanf("%d %d", &a, &b);
    UnionFind uf(b);
    priority_queue<Edge> q;
    for (int i = 1; i <= b; i++) {
        for (int j = 1; j <= b; j++) {
            int k;
            scanf("%d", &k);
            if (i < j && k != 0 && k <= a) q.push(Edge(i, j, k));
        }
    }
    while (num < b - 1 && q.size()) {
        Edge edge = q.top();
        q.pop();
        if (uf.Find(edge.u) != uf.Find(edge.v)) {
            uf.Union(edge.u, edge.v);
            ans += edge.w;
            num++;
        }
    }
    if (num == b - 1) printf("%d", ans + a);
    else printf("%d", ans + (b - num) * a);
    return 0;
}
