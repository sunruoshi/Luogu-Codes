#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 1, MOD = 1e8 - 3;

struct Node
{
    int val, id;
    bool operator<(const Node &x) const
    {
        return val < x.val;
    }
} a[N], b[N];

int n, id[N], c[N];

inline int lowbit(int x)
{
    return x & (-x);
}

void update(int x)
{
    while (x <= n)
    {
        c[x] += 1;
        x += lowbit(x);
    }
}

int query(int x)
{
    int res = 0;
    while (x)
    {
        res += c[x];
        x -= lowbit(x);
    }
    return res;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].val;
        a[i].id = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i].val;
        b[i].id = i;
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++)
    {
        id[a[i].id] = b[i].id;
    }
    int ans = 0;
    for (int i = n; i >= 1; i--)
    {
        update(id[i]);
        ans = (ans + query(id[i] - 1)) % MOD;
    }
    cout << ans << endl;
    return 0;
}
