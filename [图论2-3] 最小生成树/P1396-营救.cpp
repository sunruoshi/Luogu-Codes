#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 1e4 + 1;

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
    bool Union(int x, int y) {
        int xx = Find(x), yy = Find(y);
        if (xx == yy) return false;
        fa[xx] = yy;
        return true;
    }
};

int n, m, s, t, num, ans;

int main() {
    scanf("%d %d %d %d", &n, &m, &s, &t);
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
        if (uf.Union(edge.u, edge.v)) {
            ans = max(ans, edge.w);
            num++;
            if (uf.Find(s) == uf.Find(t)) break;
        }
    }
    printf("%d", ans);
    return 0;
}
