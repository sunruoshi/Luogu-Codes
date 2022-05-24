#include <iostream>
#define lowbit(i) ((i) & (-i))
using namespace std;

const int MAXN = 5e4 + 1, INF = 0x3f3f3f3f;

int n, q, a[MAXN], c_max[MAXN], c_min[MAXN];

void update_max(int pos, int v) {
    while (pos <= n) {
        c_max[pos] = max(c_max[pos], v);
        pos += lowbit(pos);
    }
}

void update_min(int pos, int v) {
    while (pos <= n) {
        c_min[pos] = min(c_min[pos], v);
        pos += lowbit(pos);
    }
}

int query_max(int l, int r) {
    if (l == r) return a[l];
    else {
        if (r - lowbit(r) > l) return max(c_max[r], query_max(l, r - lowbit(r)));
        else return max(a[r], query_max(l, r - 1));
    }
}

int query_min(int l, int r) {
    if (l == r) return a[l];
    else {
        if (r - lowbit(r) > l) return min(c_min[r], query_min(l, r - lowbit(r)));
        else return min(a[r], query_min(l, r - 1));
    }
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        c_min[i] = INF;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update_max(i, a[i]);
        update_min(i, a[i]);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << query_max(l, r) - query_min(l, r)<< endl;
    }
    return 0;
}
