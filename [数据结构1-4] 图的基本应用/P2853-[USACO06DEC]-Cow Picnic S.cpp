#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 1001;

int k, n, m, ans, cnt[MAXN], cows[MAXN];
vector<int> adj[MAXN];
bool visited[MAXN];

void dfs(int u) {
    visited[u] = 1;
    cnt[u]++;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (!visited[v]) dfs(v);
    }
}

int main() {
    scanf("%d %d %d", &k, &n, &m);
    for (int i = 1; i <= k; i++) {
        scanf("%d", &cows[i]);
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
    }
    for (int i = 1; i <= k; i++) {
        memset(visited, 0, sizeof(visited));
        dfs(cows[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == k) ans++;
    }
    printf("%d", ans);
    return 0;
}
