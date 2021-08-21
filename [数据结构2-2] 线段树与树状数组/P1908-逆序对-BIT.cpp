#include <cstdio>
#include <algorithm>
using namespace std;

#define lowbit(i) ((i) & (-i))

const int MAXN = 500001;

struct Node {
    int val, pos;
} arr[MAXN];

int Hash[MAXN], c[MAXN];

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
        scanf("%d", &arr[i].val);
        arr[i].pos = i;
    }
    sort(arr + 1, arr + n + 1, [](Node a, Node b) { return a.val == b.val ? a.pos < b.pos : a.val < b.val; });
    for (int i = 1; i <= n; i++) {
        Hash[arr[i].pos] = i;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        update(Hash[i], 1);
        ans += i - getSum(Hash[i]);
    }
    printf("%lld", ans);
    return 0;
}
