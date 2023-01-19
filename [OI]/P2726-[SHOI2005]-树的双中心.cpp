#include <iostream>
#include <vector>
using namespace std;

const int N = 5e4 + 1, INF = 0x3f3f3f3f;

int n, w[N], fa[N], siz[N], f[N], depth[N], son[N][2], cut, ans = INF;
vector<int> adj[N];

void dfs(int u, int pre) {
    siz[u] = w[u];
    fa[u] = pre;
    for (int v : adj[u]) {
        if (v == pre) continue;
        depth[v] = depth[u] + 1; // 根结点深度为 0
        dfs(v, u);
        siz[u] += siz[v];
        f[u] += f[v] + siz[v];
        if (siz[v] > siz[son[u][0]]) {
            son[u][1] = son[u][0];
            son[u][0] = v;
        } else if (siz[v] > siz[son[u][1]]) {
            son[u][1] = v;
        }
    }
}

void get(int u, int now, int all, int &res) {
    res = min(res, now);
    int v = son[u][0];
    if (v == cut || siz[son[u][1]] > siz[son[u][0]]) v = son[u][1];
    if (!v) return;
    if (siz[v] * 2 > all) get(v, now + all - 2 * siz[v], all, res);
}

void solve(int u) { // 自 1 向下枚举切断的边
    for (int v : adj[u]) {
        if (v == fa[u]) continue;
        // 切断 (u, v) 这条边
        cut = v;
        int A = INF, B = INF;
        for (int i = u; i; i = fa[i]) { // 重新计算 v 祖先的 siz
            siz[i] -= siz[v];
        }
        get(1, f[1] - f[v] - depth[v] * siz[v], siz[1], A);
        get(v, f[v], siz[v], B);
        ans = min(ans, A + B);
        for (int i = u; i; i = fa[i]) { // 回溯
            siz[i] += siz[v];
        }
        solve(v);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    dfs(1, 0);
    solve(1);
    cout << ans << endl;
    return 0;
}