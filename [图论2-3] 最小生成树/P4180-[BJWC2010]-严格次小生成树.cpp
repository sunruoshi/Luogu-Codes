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

struct MSTEdge {
    int v, w;
    MSTEdge(int _v, int _w) : v(_v), w(_w) {}
};

class UnionFind {
    private:
        int fa[MAXN];

    public:
        UnionFind(int n) {
            for (int i = 1; i <= n; i++) {
                fa[i] = i;
            }
        }
        int Find(int x) {
            return x == fa[x] ? x : fa[x] = Find(fa[x]);
        }
        bool Union(int x, int y) {
            int xx = Find(x), yy = Find(y);
            if (xx == yy) return false;
            fa[xx] = yy;
            return true;
        }
};

class Solution {
    private:
        int depth[MAXN], p[MAXN][31], maxWeight[MAXN][31], secWeight[MAXN][31];
        void init(int u, int fa, vector<vector<MSTEdge>> &mst) {
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
                    init(v, u, mst);
                }
            }
        }

    public:
        Solution(vector<vector<MSTEdge>> &mst) {
            memset(p, 0, sizeof(p));
            memset(maxWeight, 0, sizeof(maxWeight));
            memset(secWeight, 0, sizeof(secWeight));
            memset(depth, 0, sizeof(depth));
            init(1, 0, mst);
        }
        int solve(int x, int y) {
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
    UnionFind uf(n);
    vector<vector<MSTEdge>> mst(n + 1);
    vector<Edge> edges(m);
    vector<bool> onMST(m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.w < b.w; });
    for (int i = 0; i < m && num < n - 1; i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (uf.Union(u, v)) {
            mst[u].push_back(MSTEdge(v, w));
            mst[v].push_back(MSTEdge(u, w));
            sum += w;
            onMST[i] = 1;
            num++;
        }
    }
    long long ans = 0x3f3f3f3f3f3f3f3f;
    Solution sol(mst);
    for (int i = 0; i < m; i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (!onMST[i]) {
            int lca = sol.solve(u, v);
            long long temp1 = sol.query(u, lca, w);
            long long temp2 = sol.query(v, lca, w);
            if (max(temp1, temp2) > -INF) ans = min(ans, sum - max(temp1, temp2) + w);
        }
    }
    printf("%lld", ans);
    return 0;
}
