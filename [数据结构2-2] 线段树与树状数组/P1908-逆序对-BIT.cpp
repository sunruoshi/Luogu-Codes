#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define lowbit(i) ((i) & (-i))

const int MAXN = 500001;

struct Node {
    int val, pos;
} a[MAXN];

struct BinaryIndexedTree {
    int c[MAXN];
    BinaryIndexedTree() {
        memset(c, 0, sizeof(c));
    }
    void update(int pos) {
        while (pos < MAXN) {
            c[pos] += 1;
            pos += lowbit(pos);
        }
    }
    int query(int pos) {
        int res = 0;
        while (pos > 0) {
            res += c[pos];
            pos -= lowbit(pos);
        }
        return res;
    }
};

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i].val);
        a[i].pos = i;
    }
    sort(a + 1, a + n + 1, [](Node x, Node y) {
        return x.val == y.val ? x.pos < y.pos : x.val < y.val;
    });
    int Hash[n + 1];
    for (int i = 1; i <= n; i++) {
        Hash[a[i].pos] = i;
    }
    BinaryIndexedTree bit;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        bit.update(Hash[i]);
        ans += i - bit.query(Hash[i]);
    }
    printf("%lld", ans);
    return 0;
}
