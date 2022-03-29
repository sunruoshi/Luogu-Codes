#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

int n, m, num, ans;
vector<int> fa;

void make_set() {
    fa.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
}

int find_set(int x) {
    return x == fa[x] ? x : fa[x] = find_set(fa[x]);
}

bool union_set(int x, int y) {
    int xx = find_set(x), yy = find_set(y);
    if (xx == yy) return 0;
    fa[xx] = yy;
    return 1;
}

int main() {
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    make_set();
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.w < b.w; });
    for (auto edge : edges) {
        if (union_set(edge.u, edge.v)) {
            ans += edge.w;
            num++;
        }
        if (num == n - 1) break;
    }
    if (num != n - 1) cout << "orz";
    else cout << ans;
    return 0;
}
