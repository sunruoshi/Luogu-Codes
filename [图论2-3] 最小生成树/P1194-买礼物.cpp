#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
    Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
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
    int a, b, num = 0, ans = 0;
    scanf("%d %d", &a, &b);
    vector<Edge> edges;
    for (int i = 1; i <= b; i++) {
        for (int j = 1; j <= b; j++) {
            int k;
            scanf("%d", &k);
            if (i < j && k != 0 && k <= a) edges.push_back(Edge(i, j, k));
        }
    }
    UnionFind uf(b);
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.w < b.w; });
    for (auto edge : edges) {
        if (uf.Find(edge.u) != uf.Find(edge.v)) {
            uf.Union(edge.u, edge.v);
            ans += edge.w;
            num++;
        }
        if (num == b - 1) break;
    }
    if (num == b - 1) printf("%d", ans + a);
    else printf("%d", ans + (b - num) * a);
    return 0;
}
