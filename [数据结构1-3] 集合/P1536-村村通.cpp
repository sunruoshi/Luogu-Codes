#include <cstdio>
#include <vector>
using namespace std;;

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
        if (x != fa[x]) fa[x] = Find(fa[x]);
        return fa[x];
    }
    void Union(int x, int y) {
        fa[Find(x)] = Find(y);
    }
};

int main() {
    int n, m;
    while (1) {
        scanf("%d", &n);
        if (!n) return 0;
        scanf("%d", &m);
        if (!m) {
            printf("%d\n", n - 1);
            continue;
        }
        UnionFind uf(n);
        for (int i = 1; i <= m; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            uf.Union(x, y);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (i == uf.Find(i)) ans++;
        }
        printf("%d\n", ans - 1);
    }
    return 0;
}
