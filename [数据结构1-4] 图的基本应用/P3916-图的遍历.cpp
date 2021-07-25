#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 1;

int n, m, dis[MAXN];
vector<int> adj[MAXN];

void dfs(int u, int s) {
    if (dis[u]) return;
    dis[u] = s;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        dfs(v, s);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[v].push_back(u);
    }
    for (int i = n; i >= 1; i--) {
        dfs(i, i);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", dis[i]);
    }
    return 0;
}
