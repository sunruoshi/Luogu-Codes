#include <cstdio>
#include <vector>
using namespace std;

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
        void Union(int x, int y) {
            fa[Find(x)] = Find(y);
        }
};

int main() {
    int n, m, ans = 0;
    scanf("%d %d", &n, &m);
    UnionFind uf(3 * n);
    while (m--) {
        int opt, x, y;
        scanf("%d %d %d", &opt, &x, &y);
        if (x > n || y > n) {
            ans++;
            continue;
        }
        if (opt == 1) {
            if (uf.Find(x) == uf.Find(y + n) || uf.Find(x + n) == uf.Find(y)) ans++;
            else {
                uf.Union(x, y);
                uf.Union(x + n, y + n);
                uf.Union(x + 2 * n, y + 2 * n);
            }
        } else {
            if (uf.Find(x) == uf.Find(y) || uf.Find(x) == uf.Find(y + n)) ans++;
            else {
                uf.Union(x + n, y);
                uf.Union(x + 2 * n, y + n);
                uf.Union(x, y + 2 * n);
            }
        }
    }
    printf("%d", ans);
    return 0;
}
