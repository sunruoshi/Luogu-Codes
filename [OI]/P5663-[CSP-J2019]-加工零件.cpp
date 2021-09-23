#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 100001, INF = 0x3f3f3f3f;

struct Node {
    int v, dis;
    Node(int _v, int _dis) : v(_v), dis(_dis) {}
    bool operator < (const Node &a) const {
        return dis > a.dis;
    }
};

int n, m, t, odd[MAXN], even[MAXN];
vector<int> adj[MAXN];
bool vis_odd[MAXN], vis_even[MAXN];

int main() {
    scanf("%d %d %d", &n, &m, &t);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    fill(odd, odd + MAXN, INF);
    fill(even, even + MAXN, INF);
    priority_queue<Node> q;
    even[1] = 0;
    q.push(Node(1, 0));
    while (q.size()) {
        int u = q.top().v;
        q.pop();
        for (int v : adj[u]) {
            if (odd[u] + 1 < even[v]) {
                even[v] = odd[u] + 1;
                if (!vis_even[v]) {
                    vis_even[v] = 1;
                    q.push(Node(v, even[v]));
                }
            }
            if (even[u] + 1 < odd[v]) {
                odd[v] = even[u] + 1;
                if (!vis_odd[v]) {
                    vis_odd[v] = 1;
                    q.push(Node(v, odd[v]));
                }
            }
        }
    }
    while (t--) {
        int a, L;
        scanf("%d %d", &a, &L);
        if (L % 2) {
            if (odd[a] <= L) printf("Yes\n");
            else printf("No\n");
        } else {
            if (even[a] <= L) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
