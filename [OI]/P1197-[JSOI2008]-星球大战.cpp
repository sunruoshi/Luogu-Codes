#include <cstdio>
#include <vector>
using namespace std;

class UnionFind {
    private:
        vector<int> fa;

    public:
        int cc;
        UnionFind(int n, int k) : cc(n - k) {
            fa.resize(n);
            for (int i = 0; i < n; i++) {
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
    int n, m, k;
    scanf("%d %d", &n, &m);
    vector<vector<int>> adj(n);
    vector<bool> valid(n, 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    scanf("%d", &k);
    vector<int> destroird(k);
    vector<int> ans(k + 1);
    for (int i = 0; i < k; i++) {
        scanf("%d", &destroird[i]);
        valid[destroird[i]] = 0;
    }
    UnionFind uf(n, k);
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            if (valid[u] && valid[v] && uf.Find(u) != uf.Find(v)) {
                uf.cc--;
                uf.Union(u, v);
            }
        }
    }
    ans[k] = uf.cc;
    for (int i = k - 1; i >= 0; i--) {
        uf.cc++;
        valid[destroird[i]] = 1;
        for (int v : adj[destroird[i]]) {
            if (valid[v] && uf.Find(destroird[i]) != uf.Find(v)) {
                uf.cc--;
                uf.Union(destroird[i], v);
            }
        }
        ans[i] = uf.cc;
    }
    for (int i = 0; i <= k; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
