#include <cstdio>
#include <map>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        long long a[n], sum = 0;
        for (auto& x : a) {
            scanf("%lld", &x);
            sum += x;
            x *= n;
        }
        map<long long, int> cnt;
        long long res = 0;
        for (auto& x : a) {
            res += cnt[sum - x];
            cnt[x - sum]++;
        }
        printf("%lld\n", res);
    }
    return 0;
}
