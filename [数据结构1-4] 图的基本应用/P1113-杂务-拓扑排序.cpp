#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 1;

int n, ans, in[MAXN], len[MAXN], f[MAXN];
vector<int> adj[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int v;
        scanf("%d %d", &v, &len[i]);
        while (1) {
            int u;
            scanf("%d", &u);
            if (!u) break;
            adj[u].push_back(v);
            in[v]++;
        }
    }
    deque<int> q;
    for (int i = 1; i <= n; i++) {
        if (!in[i]) {
            q.push_back(i);
            f[i] = len[i];
        }
    }
    while (q.size()) {
        int u = q.front();
        q.pop_front();
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            f[v] = max(f[v], f[u] + len[v]);
            in[v]--;
            if (!in[v]) q.push_back(v);
        }
        ans = max(ans, f[u]);
    }
    printf("%d", ans);
    return 0;
}
