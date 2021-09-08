#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int x, y;
};

struct Edge {
    int u, v;
    double w;
    Edge(int _u, int _v, double _w) : u(_u), v(_v), w(_w) {}
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
    int n, m, num = 0;
    double ans = 0;
    scanf("%d %d", &n, &m);
    vector<Node> node(n + 1);
    vector<vector<bool>> vis(n + 1, vector<bool>(n + 1));
    auto dist = [&](Node a, Node b) {
        double dx = a.x - b.x, dy = a.y - b.y;
        return sqrt(dx * dx + dy * dy);
    };
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &node[i].x, &node[i].y);
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        vis[u][v] = vis[v][u] = 1;
    }
    vector<Edge> edges;
    for (int u = 1; u < n; u++) {
        for (int v = u + 1; v <= n; v++) {
            if (vis[u][v]) edges.push_back(Edge(u, v, 0));
            else edges.push_back(Edge(u, v, dist(node[u], node[v])));
        }
    }
    UnionFind uf(n);
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.w < b.w; });
    for (auto edge : edges) {
        if (uf.Union(edge.u, edge.v)) {
            ans += edge.w;
            num++;
        }
        if (num == n - 1) break;
    }
    printf("%.2lf", ans);
    return 0;
}
