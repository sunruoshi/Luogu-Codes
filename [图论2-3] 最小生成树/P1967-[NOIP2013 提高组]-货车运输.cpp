#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
    Edge() {}
    Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
    bool operator < (const Edge &a) const {
        return w > a.w;
    }
};

struct MSTEdge {
    int v, w;
    MSTEdge(int _v, int _w) : v(_v), w(_w) {}
};

class UnionFind {
    private:
        vector<int> fa;

    public:
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

class LCA {
    private:
        vector<vector<int>> p, w;
        vector<int> depth;
        void init(int u, int fa, int weight, vector<vector<MSTEdge>> &mst) {
            p[u][0] = fa;
            w[u][0] = weight;
            depth[u] = depth[fa] + 1;
            for (int i = 1; (1 << i) <= depth[u]; i++) {
                p[u][i] = p[p[u][i - 1]][i - 1];
                w[u][i] = min(w[u][i - 1], w[p[u][i - 1]][i - 1]);
            }
            for (auto edge : mst[u]) {
                int v = edge.v, w = edge.w;
                if (v != fa) init(v, u, w, mst);
            }
        }

    public:
        LCA(int n, int m, vector<vector<MSTEdge>> &mst) {
            p.resize(n, vector<int>(m));
            w.resize(n, vector<int>(m));
            depth.resize(n);
            init(1, 0, 0x3f3f3f3f, mst);
        }
        int solve(int x, int y, UnionFind &uf) {
            if (uf.Find(x) != uf.Find(y)) return -1;
            int res = 0x3f3f3f3f;
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
};

int main() {
    int n, m, q, num = 0;
    scanf("%d %d", &n, &m);
    UnionFind uf(n);
    vector<vector<MSTEdge>> mst(n + 1);
    vector<Edge> edge;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edge.push_back(Edge(u, v, w));
    }
    sort(edge.begin(), edge.end());
    for (int i = 0; i < m && num < n - 1; i++) {
        int u = edge[i].u, v = edge[i].v, w = edge[i].w;
        if (uf.Union(u, v)) {
            mst[u].push_back(MSTEdge(v, w));
            mst[v].push_back(MSTEdge(u, w));
            num++;
        }
    }
    LCA lca(n + 1, 31, mst);
    scanf("%d", &q);
    while (q--) {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d\n", lca.solve(x, y, uf));
    }
    return 0;
}
