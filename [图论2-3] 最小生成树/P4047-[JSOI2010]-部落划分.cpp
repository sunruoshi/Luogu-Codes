#include <cstdio>
#include <vector>
#include <cmath>
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
            fa.resize(n);
            for (int i = 0; i < n; i++) {
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
    int n, k;
    scanf("%d %d", &n, &k);
    vector<Node> node(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &node[i].x, &node[i].y);
    }
    auto dist = [&](Node a, Node b) {
        double dx = a.x - b.x, dy = a.y - b.y;
        return sqrt(dx * dx + dy * dy);
    };
    vector<Edge> edges;
    for (int u = 0; u < n - 1; u++) {
        for (int v = u + 1; v < n; v++) {
            edges.push_back(Edge(u, v, dist(node[u], node[v])));
        }
    }
    UnionFind uf(n);
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.w < b.w; });
    int num = 0;
    for (auto edge : edges) {
        if (uf.Union(edge.u, edge.v)) num++;
        if (num == n - k + 1) {
            printf("%.2lf", edge.w);
            break;
        }
    }
    return 0;
}
