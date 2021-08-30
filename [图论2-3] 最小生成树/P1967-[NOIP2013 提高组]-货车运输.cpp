#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 10000
#define INF 0x3f3f3f3f
using namespace std;

struct Edge {
    int u, v, w;
    Edge() {}
    Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
    bool operator < (const Edge &a) const {
        return w > a.w;
    }
};

struct Node {
    int v, w;
    Node(int _v, int _w) : v(_v), w(_w) {}
};

struct UnionFind {
    vector<int> fa;
    UnionFind(int n) {
        fa.resize(n + 1);
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

int n, m, q, num, p[MAXN][31], w[MAXN][31], depth[MAXN];
vector<Edge> edge;
vector<vector<Node>> mst;

void dfs(int root, int fa, int dis) {
    p[root][0] = fa;
    w[root][0] = dis;
    depth[root] = depth[fa] + 1;
    for (int i = 1; (1 << i) <= depth[root]; i++) {
        p[root][i] = p[p[root][i - 1]][i - 1];
        w[root][i] = min(w[root][i - 1], w[p[root][i - 1]][i - 1]);
    }
    for (auto node : mst[root]) {
        if (node.v != fa) dfs(node.v, root, node.w);
    }
}

int lca(int x, int y, UnionFind uf) {
    if (uf.Find(x) != uf.Find(y)) return -1;
    int res = INF;
    if (depth[x] < depth[y]) swap(x, y);
    int temp = depth[x] - depth[y];
    for (int i = 0; temp > 0; i++) {
        if (temp & 1) {
            res = min(res, w[x][i]);
            x = p[x][i];
        }
        temp >>= 1;
    }
    if (x == y) return res;
    for (int i = 30; i >= 0; i--) {
        if (p[x][i] != p[y][i]) {
            res = min(res, min(w[x][i], w[y][i]));
            x = p[x][i];
            y = p[y][i];
        }
    }
    res = min(res, min(w[x][0], w[y][0]));
    return res;
}

int main() {
    scanf("%d %d", &n, &m);
    UnionFind uf(n);
    mst.resize(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edge.push_back(Edge(u, v, w));
    }
    sort(edge.begin(), edge.end());
    for (int i = 0; i < m && num < n - 1; i++) {
        int u = edge[i].u, v = edge[i].v, w = edge[i].w;
        if (uf.Union(u, v)) {
            mst[u].push_back(Node(v, w));
            mst[v].push_back(Node(u, w));
            num++;
        }
    }
    dfs(1, 0, INF);
    scanf("%d", &q);
    while (q--) {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d\n", lca(x, y, uf));
    }
    return 0;
}
