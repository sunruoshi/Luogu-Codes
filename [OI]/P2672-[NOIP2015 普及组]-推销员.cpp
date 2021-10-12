#include <cstdio>
#include <algorithm>
#define MAXN 100001
using namespace std;

struct Node {
    int dis, val;
};

int sum[MAXN], leftMax[MAXN], rightMax[MAXN];

int main() {
    // freopen("salesman.in", "r", stdin);
    // freopen("salesman.out", "w", stdout);
    int n;
    scanf("%d", &n);
    Node node[n + 1];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &node[i].dis);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &node[i].val);
    }
    sort(node + 1, node + n + 1, [](Node x, Node y) { return x.val > y.val; });
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + node[i].val;
    }
    for (int i = 1; i <= n; i++) {
        leftMax[i] = max(leftMax[i - 1], node[i].dis << 1);
    }
    for (int i = n; i >= 1; i--) {
        rightMax[i] = max(rightMax[i + 1], (node[i].dis << 1) + node[i].val);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n", max(sum[i] + leftMax[i], sum[i - 1] + rightMax[i]));
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}
