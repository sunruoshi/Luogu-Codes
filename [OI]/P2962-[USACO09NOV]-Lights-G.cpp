#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

typedef long long ll;
int n, m;
unordered_map<ll, ll> f;
ll a[40], ans = 0x3f3f3f3f3f3f3f3f;

int main()
{
    cin >> n >> m;
    // 进行预处理
    a[0] = 1;
    for (int i = 1; i < n; i++)
    {
        a[i] = a[i - 1] << 1;
    }
    // 对输入的边的情况进行处理
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        a[u] |= ((ll)1 << v);
        a[v] |= ((ll)1 << u);
    }
    // 对前一半进行搜索
    for (int i = 0; i < (1 << (n / 2)); i++)
    {
        ll t = 0, cnt = 0;
        for (int j = 0; j < n / 2; j++)
        {
            if ((i >> j) & 1)
            {
                t ^= a[j];
                cnt++;
            }
        }
        f[t] = f.count(t) ? min(f[t], cnt) : cnt;
    }
    // 对后一半进行搜索
    for (int i = 0; i < (1 << (n - n / 2)); i++)
    {
        ll t = 0, cnt = 0;
        for (int j = 0; j < (n - n / 2); j++)
        {
            if ((i >> j) & 1)
            {
                t ^= a[n / 2 + j];
                cnt++;
            }
        }
        if (f.count((((ll)1 << n) - 1) ^ t))
        {
            ans = min(ans, cnt + f[(((ll)1 << n) - 1) ^ t]);
        }
    }

    cout << ans << endl;

    return 0;
}