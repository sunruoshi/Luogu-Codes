#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 500001
using namespace std;

int n, m, root, ans[MAXN];
vector<int> adj[MAXN];
vector<pair<int, int>> query[MAXN];

class Tarjan {
    private:
        vector<int> fa, visited;
        int Find(int x) {
            return x == fa[x] ? x : fa[x] = Find(fa[x]);
        }

    public:
        Tarjan(int n) {
            fa.resize(n + 1);
            visited.resize(n + 1);
        }
        void solve(int u) {
            fa[u] = u;
            visited[u] = 1;
            for (int v : adj[u]) {
                if (!visited[v]) {
                    solve(v);
                    fa[v] = u;
                }
            }
            for (auto q : query[u]) {
                if (visited[q.first]) {
                    ans[q.second] = Find(q.first);
                }
            }
        }
};

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
    Tarjan lca(n);
    lca.solve(root);
    for (int i = 1; i <= m; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
