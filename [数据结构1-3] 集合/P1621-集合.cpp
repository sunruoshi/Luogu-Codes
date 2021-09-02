#include <cstdio>
#include <vector>
using namespace std;

class UnionFind {
private:
    vector<int> fa;

public:
    UnionFind(int a, int b) {
        fa.resize(b + 1);
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
    int a, b, p;
    scanf("%d %d %d", &a, &b, &p);
    int ans = b - a + 1;
    vector<bool> notPrime(b + 1, 0);
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
