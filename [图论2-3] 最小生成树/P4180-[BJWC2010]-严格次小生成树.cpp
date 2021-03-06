#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXN 100001
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

        int fa[MAXN], depth[MAXN], p[MAXN][31], maxWeight[MAXN][31], secWeight[MAXN][31];
        vector<Edge> mst[MAXN];

        int Find(int x) {
            return x == fa[x] ? x : fa[x] = Find(fa[x]);
        }

    public:
        Solution(int n) {
            memset(p, 0, sizeof(p));
            memset(maxWeight, 0, sizeof(maxWeight));
            memset(secWeight, 0, sizeof(secWeight));
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

        void init(int u, int fa) {
            p[u][0] = fa;
            secWeight[u][0] = -INF;
            depth[u] = depth[fa] + 1;
            for (int i = 1; (1 << i) <= depth[u]; i++) {
                p[u][i] = p[p[u][i - 1]][i - 1];
                int temp[4] = {
                    maxWeight[u][i - 1], maxWeight[p[u][i - 1]][i - 1],
                    secWeight[u][i - 1], secWeight[p[u][i - 1]][i - 1]
                };
                sort(temp, temp + 4);
                maxWeight[u][i] = temp[3];
                int pos = 2;
                while (pos >= 0 && temp[pos] == temp[3]) pos--;
                secWeight[u][i] = (pos == -1 ? -INF : temp[pos]);
            }
            for (auto edge : mst[u]) {
                int v = edge.v, w = edge.w;
                if (v != fa) {
                    maxWeight[v][0] = w;
                    init(v, u);
                }
            }
        }

        void addEdge(int u, int v, int w) {
            mst[u].push_back(Edge(v, w));
            mst[v].push_back(Edge(u, w));
        }

        int lca(int x, int y) {
            if (depth[x] < depth[y]) swap(x, y);
            int temp = depth[x] - depth[y];
            for (int i = 0; temp > 0; i++) {
                if (temp & 1) x = p[x][i];
                temp >>= 1;
            }
            if (x == y) return x;
            for (int i = 30; i >= 0; i--) {
                if (p[x][i] != p[y][i]) {
                    x = p[x][i];
                    y = p[y][i];
                }
            }
            return p[x][0];
        }

        int query(int x, int y, int val) {
            int res = -INF;
            for (int i = 30; i >= 0; i--) {
                if (depth[p[x][i]] >= depth[y]) {
                    if (val != maxWeight[x][i]) res = max(res, maxWeight[x][i]);
                    else res = max(res, secWeight[x][i]);
                    x = p[x][i];
                }
            }
            return res;
        }
};

int main() {
    int n, m, num = 0;
    long long sum = 0;
    scanf("%d %d", &n, &m);
    vector<Edge> edges(m);
    vector<bool> onMST(m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.w < b.w; });
    Solution solve(n);
    for (int i = 0; i < m && num < n - 1; i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (solve.Union(u, v)) {
            solve.addEdge(u, v, w);
            sum += w;
            onMST[i] = 1;
            num++;
        }
    }
    solve.init(1, 0);
    long long ans = 0x3f3f3f3f3f3f3f3f;
    for (int i = 0; i < m; i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (!onMST[i]) {
            int lca = solve.lca(u, v);
            long long maxUV = max(solve.query(u, lca, w), solve.query(v, lca, w));
            if (maxUV > -INF) ans = min(ans, sum - maxUV + w);
        }
    }
    printf("%lld", ans);
    return 0;
}
