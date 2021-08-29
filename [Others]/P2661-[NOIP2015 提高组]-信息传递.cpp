#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans = 0x3f3f3f3f;

struct UnionFind {
    vector<int> fa, dis;
    UnionFind(int n) {
        fa.resize(n + 1);
        dis.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
        }
    }
    int Find(int x) {
        if (x != fa[x]) {
            int temp = fa[x];
            fa[x] = Find(fa[x]);
            dis[x] += dis[temp];
        }
        return fa[x];
    }
    void Union(int x, int y) {
        int xx = Find(x), yy = Find(y);
        if (xx != yy) {
            fa[xx] = yy;
            dis[x] = dis[y] + 1;
        } else {
            ans = min(ans, dis[x] + dis[y] + 1);
        }
    }
};

int main() {
    scanf("%d", &n);
    UnionFind uf(n);
    for (int x = 1; x <= n; x++) {
        int y;
        scanf("%d", &y);
        uf.Union(x, y);
    }
    printf("%d", ans);
    return 0;
}
