#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, w;
    scanf("%d %d", &n, &w);
    vector<int> myList;
    for (int i = 1; i <= n; i++) {
        int d, cur = max(1, i * w / 100);
        scanf("%d", &d);
        myList.insert(lower_bound(myList.begin(), myList.end(), d), d);
        printf("%d ", myList[myList.size() - cur]);
    }
    return 0;
}
