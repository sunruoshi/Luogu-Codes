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
    // ð������
    for (int i = n - 1; i > 0; i--) {
        bool flag = 1;
        for (int j = 0; j < i; j++) {
            // �����Ҫð�ݣ�˵���ҵ�һ�������
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
                ans++; // �ۼӴ�
                flag = 0;
            }
        }
        if (flag) break;
    }
    printf("%d", ans);
    return 0;
}
