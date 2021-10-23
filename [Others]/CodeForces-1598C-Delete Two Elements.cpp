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
        }
        if ((sum << 1) % n) {
            printf("0\n");
            continue;
        }
        map<long long, int> cnt;
        long long res = 0, target = (sum << 1) / n;
        for (auto& x : a) {
            if (x <= target && cnt[target - x]) res += cnt[target - x];
            cnt[x]++;
        }
        printf("%lld\n", res);
    }
    return 0;
}
