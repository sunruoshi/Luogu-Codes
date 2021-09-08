#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
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
            return x == fa[x] ? x : fa[x] = Find(fa[x]);
        }
        bool Union(int x, int y) {
            int xx = Find(x), yy = Find(y);
            if (xx == yy) return false;
            fa[xx] = yy;
            return true;
        }
};

int main() {
    int n, m, k, num = 0, ans = 0;
    scanf("%d %d %d", &n, &m, &k);
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    UnionFind uf(n);
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.w < b.w; });
    for (auto edge : edges) {
        if (uf.Union(edge.u, edge.v)) {
            ans += edge.w;
            num++;
        }
        if (num == n - k) break;
    }
    if (num == n - k) printf("%d", ans);
    else printf("No Answer");
    return 0;
}
