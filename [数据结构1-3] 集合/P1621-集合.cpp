#include <cstdio>

const int MAXN = 1e5 + 1;

int a, b, p;
bool notPrime[MAXN];

struct UnionFind {
    int fa[MAXN];
    UnionFind(int a, int b) {
        for (int i = a; i<= b; i++) {
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
    scanf("%d %d %d", &a, &b, &p);
    int ans = b - a + 1;
    UnionFind uf(a, b);
    for (int i = 2; i <= b; i++) {
        if (!notPrime[i]) {
            for (int j = i * 2; j <= b; j += i) {
                notPrime[j] = 1;
                if (i >= p && j - i >= a && uf.Find(j) != uf.Find(j - i)) {
                    uf.Union(j, j - i);
                    ans--;
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}
