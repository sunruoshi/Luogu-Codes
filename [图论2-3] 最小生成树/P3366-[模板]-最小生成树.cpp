#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
    bool operator < (const Edge &e) const {
        return w < e.w;
    }
};

vector<int> fa;

void make_set(int n) {
    fa.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
}

int query(int x) {
    return x == fa[x] ? x : fa[x] = query(fa[x]);
}

bool merge(int x, int y) {
    int xx = query(x), yy = query(y);
    if (xx == yy) return 0;
    fa[xx] = yy;
    return 1;
}

int main() {
    int n, m, cnt = 0, ans = 0;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    // Kruskal
    make_set(n);
    sort(edges.begin(), edges.end());
    for (auto edge : edges) {
        if (merge(edge.u, edge.v)) {
            ans += edge.w;
            cnt++;
        }
        if (cnt == n - 1) break;
    }
    if (cnt != n - 1) cout << "orz";
    else cout << ans;
    return 0;
}
