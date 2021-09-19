#include <cstdio>
#include <unordered_map>
using namespace std;

int main() {
    int n, q;
    scanf("%d", &n);
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int num;
        scanf("%d", &num);
        mp[num] = i;
    }
    scanf("%d", &q);
    while (q--) {
        int num;
        scanf("%d", &num);
        printf("%d\n", mp[num]);
    }
    return 0;
}
