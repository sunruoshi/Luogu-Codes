#include <cstdio>
using namespace std;

const int MAXN = 101;

int n, maxh = 1, maxw, w[MAXN];

struct Node {
    int fa, h;
} node[MAXN];

int main() {
    int n, u, v;
    scanf("%d", &n);
    node[1].h = w[1] = 1;
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &u, &v);
        node[v].fa = u;
        node[v].h = node[u].h + 1;
        if (node[v].h > maxh) maxh = node[v].h;
        w[node[v].h]++;
    }
    scanf("%d %d", &u, &v);
    for (int i = 1; i <= maxh; i++) {
        if (w[i] > maxw) maxw = w[i];
    }
    printf("%d\n%d\n", maxh, maxw);
    if (u == v) {
        printf("0");
        return 0;
    }
    int d1 = 0, d2 = 0;
    while (node[u].fa != node[v].fa) {
        if (node[u].fa == v) {
            printf("%d", (d1 + 1) * 2);
            return 0;;
        }
        if (node[v].fa == u) {
            printf("%d", d2 + 1);
            return 0;
        }
        if (node[u].h > node[v].h) {
            d1++;
            u = node[u].fa;
        }
        if (node[v].h > node[u].h) {
            d2++;
            v = node[v].fa;
        }
        if (node[u].h == node[v].h && node[u].fa != node[v].fa) {
            d1++;
            d2++;
            u = node[u].fa;
            v = node[v].fa;
        }
    }
    printf("%d", (d1 + 1) * 2 + d2 + 1);
    return 0;
}
