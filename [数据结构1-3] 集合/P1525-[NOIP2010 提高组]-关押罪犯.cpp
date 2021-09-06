#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
    int u, v, w;
    Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
    bool operator < (const Edge &a) const {
        return w < a.w;
    }
};

class UnionFind {
    private:
        vector<int> fa;

    public:
        UnionFind(int n) {
            fa.resize(n);
            for (int i = 1; i <= n; i++) {
                fa[i] = i;
            }
        }
        int Find(int x) {
            return x == fa[x] ? x : fa[x] = Find(fa[x]);
        }
        void Union(int x, int y) {
            fa[Find(x)] = Find(y);
        }
};

int main() {
    int n, m, ans = 0;
    scanf("%d %d", &n, &m);
    priority_queue<Edge> q;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        q.push(Edge(u, v, w));
    }
    UnionFind uf(2 * n + 1);
    while (q.size()) {
        int u = q.top().u, v = q.top().v, w = q.top().w;
        q.pop();
        if (uf.Find(u) == uf.Find(v) || uf.Find(u + n) == uf.Find(v + n)) {
            ans = w;
            break;
        }
        uf.Union(u + n, v);
        uf.Union(u, v + n);
    }
    printf("%d", ans);
    return 0;
}
