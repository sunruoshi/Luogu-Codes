#include <cstdio>
#include <algorithm>
using namespace std;

#define lowbit(i) ((i) & (-i))

const int MAXN = 500001;

struct Node {
    int val, pos;
} temp[MAXN];

int a[MAXN], c[MAXN];

void update(int x, int v) {
    for (int i = x; i < MAXN; i += lowbit(i)) {
        c[i] += v;
    }
}

int getSum(int x) {
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        sum += c[i];
    }
    return sum;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &temp[i].val);
        temp[i].pos = i;
    }
    sort(temp + 1, temp + n + 1, [](Node a, Node b) { return a.val == b.val ? a.pos < b.pos : a.val < b.val; });
    for (int i = 1; i <= n; i++) {
        a[temp[i].pos] = i;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        update(a[i], 1);
        ans += i - getSum(a[i]);
    }
    printf("%lld", ans);
    return 0;
}
