#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int freq[n + 1]; // 频度数组，用于计数排序
    for (int i = 1; i <= n; i++) {
        freq[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int d;
        cin >> d;
        freq[d]++;
    }
    // 从频度数组中依次取出值输出
    for (int i = 1; i <= n; i++) {
        while (freq[i]) {
            cout << i << " ";
            freq[i]--;
        }
    }
    return 0;
}
