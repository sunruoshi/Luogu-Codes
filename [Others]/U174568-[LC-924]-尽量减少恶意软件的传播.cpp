#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct UnionFind {
    vector<int> fa, size;
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
        if (size[xx] > size[yy]) swap(xx, yy);
        fa[xx] = yy;
        size[yy] += size[xx];
    }
    int getSize(int x) {
        return size[x];
    }
};

int main() {
    int n, m, max_size = 0, ans = -1;
    scanf("%d", &n);
    int graph[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    scanf("%d", &m);
    int initial[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &initial[i]);
    }
    int cnt[n];
    memset(cnt, 0, sizeof(cnt));
    sort(initial, initial + m, greater<int>());
    UnionFind uf(n);
    for (int u : initial) {
        cnt[uf.Find(u)]++;
    }
    for (int u: initial) {
        int uu = uf.Find(u);
        if (cnt[uu] == 1) {
            int size = uf.getSize(uu);
            if (size >= max_size) {
                max_size = size;
                ans = u;
            }
        }
    }
    if (ans == -1) ans = initial[m - 1];
    printf("%d", ans);
    return 0;
}
