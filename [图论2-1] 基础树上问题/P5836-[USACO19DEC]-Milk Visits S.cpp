#include <iostream>
#include <vector>
using namespace std;

struct UnionFind {
    vector<int> fa;
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
    cin >> n >> m;
    char s[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    UnionFind uf(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        if (s[u] == s[v]) uf.Union(u, v);
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        char type;
        cin >> u >> v >> type;
        if (uf.Find(u) == uf.Find(v) && s[u] != type) cout << 0;
        else cout << 1;
    }
    return 0;
}
