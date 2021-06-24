#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    // 冒泡排序
    for (int i = n - 1; i > 0; i--) {
        bool flag = 1;
        for (int j = 0; j < i; j++) {
            // 如果需要冒泡，说明找到一个逆序对
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
                ans++; // 累加答案
                flag = 0;
            }
        }
        if (flag) break;
    }
    printf("%d", ans);
    return 0;
}
