#include <cstdio>
#include <set>
#include <algorithm>
#define INF 0x7f7f7f7f
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    set<int> numSet;
    while (n--) {
        int opt, len;
        scanf("%d %d", &opt, &len);
        if (opt == 1) {
            if (numSet.count(len)) printf("Already Exist\n");
            else numSet.insert(len);
        } else {
            if (numSet.empty()) printf("Empty\n");
            else {
                if (numSet.count(len)) {
                    printf("%d\n", len);
                    numSet.erase(numSet.find(len));
                } else {
                    auto res = numSet.insert(len);
                    auto lower = res.first;
                    auto upper = res.first;
                    int len1 = lower == numSet.begin() ? INF : *(--lower);
                    int len2 = ++upper == numSet.end() ? INF : *upper;
                    if (abs(len - len1) < abs(len - len2)) {
                        printf("%d\n", len1);
                        numSet.erase(lower);
                    } else if (abs(len - len1) > abs(len - len2)){
                        printf("%d\n", len2);
                        numSet.erase(upper);
                    } else {
                        printf("%d\n", min(len1, len2));
                        numSet.erase(len1 < len2 ? lower : upper);
                    }
                    numSet.erase(res.first);
                }
            }
        }
    }
    return 0;
}
