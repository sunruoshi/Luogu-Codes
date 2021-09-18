#include <cstdio>
#include <unordered_set>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        unordered_set<int> numSet;
        while (n--) {
            int num;
            scanf("%d", &num);
            if (numSet.count(num)) continue;
            numSet.insert(num);
            printf("%d ", num);
        }
        printf("\n");
    }
    return 0;
}
