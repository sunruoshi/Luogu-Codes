#include <iostream>
#include <vector>
#include <deque>
#define MAXN 10001
using namespace std;

bool vis[MAXN], inStack[MAXN];
vector<int> adj[MAXN];
deque<int> topo;

bool dfs(int u) {
    inStack[u] = 1;
    for (int v : adj[u]) {
        if (inStack[v]) return 0;
        else if (!vis[v] && !dfs(v)) return 0;
    }
    inStack[u] = 0;
    vis[u] = 1;
    topo.push_front(u);
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int u = 1; u <= n; u++) {
        if (!vis[u]) {
            if (!dfs(u)) {
                printf("Not DAG\n");
                return 0;
            }
        }
    }
    auto it = topo.begin();
    while (it != topo.end()) {
        printf("%d ", *it);
        it++;
    }
    return 0;
}
