#include <cstdio>
#include <unordered_map>
#define MAXN 200001
using namespace std;

int n, a[MAXN];
long long c, cnt;
unordered_map<int, int> mp;

int main() {
    scanf("%d %lld", &n, &c);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        mp[a[i]]++;
        a[i] -= c;
    }
    for (int i = 1; i <= n; i++) {
        cnt += mp[a[i]];
    }
    printf("%lld", cnt);
    return 0;
}
