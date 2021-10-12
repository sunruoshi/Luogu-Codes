#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Node {
    int s, a;
};

int main() {
    // freopen("salesman.in", "r", stdin);
    // freopen("salesman.out", "w", stdout);
    int n;
    scanf("%d", &n);
    int sum[n + 1], leftMax[n + 1], rightMax[n + 1];
    memset(sum, 0, sizeof(sum));
    memset(leftMax, 0, sizeof(leftMax));
    memset(rightMax, 0, sizeof(rightMax));
    Node node[n + 1];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &node[i].s);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &node[i].a);
    }
    sort(node + 1, node + n + 1, [](Node x, Node y) { return x.a > y.a; });
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + node[i].a;
    }
    for (int i = 1; i <= n; i++) {
        leftMax[i] = max(leftMax[i - 1], node[i].s << 1);
    }
    for (int i = n; i >= 1; i--) {
        rightMax[i] = max(rightMax[i + 1], (node[i].s << 1) + node[i].a);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n", max(sum[i] + leftMax[i], sum[i - 1] + rightMax[i]));
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}
