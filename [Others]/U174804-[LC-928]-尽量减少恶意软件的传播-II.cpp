#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_set>
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
        return size[Find(x)];
    }
};

int main() {
    int n, m, ans, maxSize = -1;
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
    UnionFind uf(n);
    bool clean[n];
    fill(clean, clean + n, 1);
    for (int u: initial) {
        clean[u] = 0;
    }
    for (int u = 0; u < n - 1; u++) {
        if (!clean[u]) continue;
        for (int v = u + 1; v < n; v++) {
            if (clean[v] && graph[u][v]) uf.Union(u, v);
        }
    }
    int cnt[n];
    memset(cnt, 0, sizeof(cnt));
    map<int, unordered_set<int>> Map;
    for (int u: initial) {
        unordered_set<int> compo;
        for (int v = 0; v < n; v++) {
            if (clean[v] && graph[u][v]) compo.insert(uf.Find(v));
        }
        Map.emplace(u, compo);
        for (int c: compo) {
            cnt[c]++;
        }
    }
    for (auto element : Map) {
        int size = 0, u = element.first;
        unordered_set<int> compo = element.second;
        for (int c : compo) {
            if (cnt[c] == 1) size += uf.getSize(c);
        }
        if (size > maxSize || (size == maxSize && u < ans)) {
            maxSize = size;
            ans = u;
        }
    }
    printf("%d", ans);
    return 0;
}
