#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#define MAXN 100001
using namespace std;

struct Edge {
    int v, w;
    Edge(int _v, int _w) : v(_v), w(_w) {}
};

struct Node {
    int v, dis;
    Node(int _v, int _dis) : v(_v), dis(_dis) {}
};

class minHeap {
    private:
        Node* heap;
        int heapSize;

    public:
        minHeap(int n) : heap((Node*) malloc((n + 1) * sizeof(Node))), heapSize(0) {}

        void push(Node x) {
            heap[++heapSize] = x;
            int cur = heapSize;
            while (cur > 1) {
                int fa = cur >> 1;
                if (heap[cur].dis >= heap[fa].dis) break;
                swap(heap[cur], heap[fa]);
                cur = fa;
            }
        }

        Node pop() {
            Node res = heap[1];
            heap[1] = heap[heapSize--];
            int fa = 1;
            while ((fa << 1) <= heapSize) {
                int child = fa << 1;
                if (child < heapSize && heap[child + 1].dis < heap[child].dis) child++;
                if (heap[fa].dis <= heap[child].dis) break;
                swap(heap[fa], heap[child]);
                fa = child;
            }
            return res;
        }

        int size() {
            return heapSize;
        }
};

vector<Edge> adj[MAXN];
int n, m, s, dis[MAXN];
bool visited[MAXN];

int main() {
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back(Edge(v, w));
    }
    memset(dis, 0x3f, sizeof(dis));
    minHeap q(n);
    dis[s] = 0;
    q.push(Node(s, 0));
    while (q.size()) {
        int u = q.pop().v;
        if (visited[u]) continue;
        visited[u] = 1;
        for (Edge edge : adj[u]) {
            int v = edge.v, w = edge.w;
            if (!visited[v] && dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                q.push(Node(v, dis[v]));
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", dis[i]);
    }
    return 0;
}
