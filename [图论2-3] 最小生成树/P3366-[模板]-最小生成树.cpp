#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXV = 5001, MAXE = 200001;

struct Edge {
    int u, v, w;
    bool operator < (const Edge &a) const {
        return w < a.w;
    }
} edge[MAXE];

struct UnionFind {
    int fa[MAXV];
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

int kruskal(int n, int m) {
    int ans = 0, num = 0;
    UnionFind uf(n);
    sort(edge, edge + m);
    for (int i = 1; i <= m; i++) {
        int u = edge[i].u, v = edge[i].v;
        if (uf.Find(u) != uf.Find(v)) {
            uf.Union(u, v);
            ans += edge[i].w;
            num++;
            if (num == n - 1) break;
        }
    }
    if (num != n - 1) return -1;
    else return ans;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
    }
    int ans = kruskal(n, m);
    if (ans == -1) printf("orz");
    else printf ("%d", ans);
    return 0;
}
