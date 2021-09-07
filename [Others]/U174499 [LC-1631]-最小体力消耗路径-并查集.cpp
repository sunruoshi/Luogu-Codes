#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

struct Edge {
    int u, v, w;
    Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
    bool operator < (const Edge &a) const {
        return w > a.w;
    }
};

class UnionFind {
    private:
        vector<int> fa, size;

    public:
        UnionFind(int n) {
            fa.resize(n);
            size.resize(n);
            for (int i = 0; i < n; i++) {
                fa[i] = i;
                size[i] = 1;
            }
        }
        int Find(int x) {
            if (x != fa[x]) fa[x] = Find(fa[x]);
            return fa[x];
        }
        void Union(int x, int y) {
            int xx = Find(x), yy = Find(y);
            if (xx == yy) return;
            if (xx > yy) swap(xx, yy);
            fa[xx] = yy;
            size[yy] += size[xx];
        }
};

int main() {
    int n, m, ans = 0;
    scanf("%d %d", &n, &m);
    int heights[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &heights[i][j]);
        }
    }
    priority_queue<Edge> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int id = i * m + j;
            if (i > 0) q.push(Edge(id - m, id, abs(heights[i][j] - heights[i - 1][j])));
            if (j > 0) q.push(Edge(id - 1, id, abs(heights[i][j] - heights[i][j - 1])));
        }
    }
    UnionFind uf(n * m);
    while (q.size()) {
        Edge edge = q.top();
        q.pop();
        uf.Union(edge.u, edge.v);
        if (uf.Find(0) == uf.Find(n * m - 1)) {
            ans = edge.w;
            break;
        }
    }
    printf("%d", ans);
    return 0;
}
