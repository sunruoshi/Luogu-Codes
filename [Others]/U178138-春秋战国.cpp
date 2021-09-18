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
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    UnionFind uf(n << 1);
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        uf.Union(x, y + n);
        uf.Union(x + n, y);
    }
    while (q--) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (uf.Find(x) == uf.Find(y) || uf.Find(x + n) == uf.Find(y + n)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
