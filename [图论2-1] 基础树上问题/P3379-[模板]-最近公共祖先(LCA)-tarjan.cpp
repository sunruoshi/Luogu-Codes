#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 500001
using namespace std;

int n, m, root, fa[MAXN], ans[MAXN];
bool visited[MAXN];
vector<int> adj[MAXN];
vector<pair<int, int>> query[MAXN];

int Find(int x) {
    return x == fa[x] ? x : fa[x] = Find(fa[x]);
}

void tarjan(int u) {
    fa[u] = u;
    visited[u] = 1;
    for (int v : adj[u]) {
        if (!visited[v]) {
            tarjan(v);
            fa[v] = u;
        }
    }
    for (auto q : query[u]) {
        if (visited[q.first]) {
            ans[q.second] = Find(q.first);
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &root);
    for (int i = 1; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        query[x].push_back(make_pair(y, i));
        query[y].push_back(make_pair(x, i));
    }
    tarjan(root);
    for (int i = 1; i <= m; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
