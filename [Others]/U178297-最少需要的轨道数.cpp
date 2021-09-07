#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        int num, pos;
        scanf("%d", &num);
        if (num > nums[cnt]) {
            pos = ++cnt;
        } else {
            int left = 0, right = cnt;
            while (left < right) {
                int mid = (left + right) >> 1;
                if (nums[mid] >= num) right = mid;
                else left = mid + 1;
            }
            pos = left;
        }
        nums[pos] = num;
    }
    printf("%d", cnt);
    return 0;
}
