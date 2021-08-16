#include <cstdio>
#include <vector>
#include <deque>
using namespace std;

const int MAXN = 10000;

int n, in[MAXN];
vector<int> adj[MAXN];

int main() {
    scanf("%d", &n);
    for (int u = 0; u < n; u++) {
        int m;
        scanf("%d", &m);
        if (!m) continue;
        for (int i = 0; i < m; i++) {
            int v;
            scanf("%d", &v);
            adj[v].push_back(u);
            in[u]++;
        }
    }
    deque<int> q;
    for (int i = 0; i < n; i++) {
        if (!in[i]) q.push_back(i);
    }
    while (q.size()) {
        int u = q.front();
        q.pop_front();
        for (int v : adj[u]) {
            in[v]--;
            if (!in[v]) q.push_back(v);
        }
    }
    for (int i = 0; i < n; i++) {
        if (!in[i]) printf("%d ", i);
    }
    return 0;
}
