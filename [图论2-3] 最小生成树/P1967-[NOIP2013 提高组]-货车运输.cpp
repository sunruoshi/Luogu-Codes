#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXN 10000
#define INF 0x3f3f3f3f
using namespace std;

struct Edge {
    int u, v, w;
};

class Solution {
    private:
        struct Edge {
            int v, w;
            Edge(int _v, int _w) : v(_v), w(_w) {}
        };

        int fa[MAXN], depth[MAXN], p[MAXN][31], w[MAXN][31];
        vector<Edge> mst[MAXN];

        int Find(int x) {
            return x == fa[x] ? x : fa[x] = Find(fa[x]);
        }

    public:
        Solution(int n) {
            memset(p, 0, sizeof(p));
            memset(w, 0, sizeof(w));
            memset(depth, 0, sizeof(depth));
            for (int i = 1; i <= n; i++) {
                fa[i] = i;
            }
        }

        bool Union(int x, int y) {
            int xx = Find(x), yy = Find(y);
            if (xx == yy) return false;
            fa[xx] = yy;
            return true;
        }

        void addEdge(int u, int v, int w) {
            mst[u].push_back(Edge(v, w));
            mst[v].push_back(Edge(u, w));
        }

        void init(int u, int fa, int weight) {
            p[u][0] = fa;
            w[u][0] = weight;
            depth[u] = depth[fa] + 1;
            for (int i = 1; (1 << i) <= depth[u]; i++) {
                p[u][i] = p[p[u][i - 1]][i - 1];
                w[u][i] = min(w[u][i - 1], w[p[u][i - 1]][i - 1]);
            }
            for (auto edge : mst[u]) {
                int v = edge.v, w = edge.w;
                if (v != fa) init(v, u, w);
            }
        }

        int lca(int x, int y) {
            if (Find(x) != Find(y)) return -1;
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
};

int main() {
    int n, m, q, num = 0;
    scanf("%d %d", &n, &m);
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.w > b.w; });
    Solution solve(n);
    for (int i = 0; i < m && num < n - 1; i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (solve.Union(u, v)) {
            solve.addEdge(u, v, w);
            num++;
        }
    }
    solve.init(1, 0, INF);
    scanf("%d", &q);
    while (q--) {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d\n", solve.lca(x, y));
    }
    return 0;
}
