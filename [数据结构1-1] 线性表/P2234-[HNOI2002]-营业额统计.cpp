#include <cstdio>
#include <set>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    set<int> rev;
    for (int i = 0; i < n; i++) {
        int d;
        scanf("%d", &d);
        if (rev.empty()) {
            rev.insert(d);
            ans += d;
            continue;
        }
        set<int>::iterator pos = rev.lower_bound(d);
        if (*pos != d) {
            set<int>::iterator it = pos;
            it--;
            if (pos == rev.begin()) {
                ans += abs(d - *pos);
            } else if (pos == rev.end()) {
                ans += abs(d - *it);
            } else {
                ans += min(abs(d - *it), abs(d - *pos));
            }
            rev.insert(pos, d);
        }
    }
    printf("%d", ans);
    return 0;
}
