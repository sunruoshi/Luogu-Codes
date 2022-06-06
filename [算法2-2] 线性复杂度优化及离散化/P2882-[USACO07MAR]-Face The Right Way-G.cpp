#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e4 + 1;

int n;
bool a[N], d[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        a[i] = c == 'B' ? 0 : 1;
    }
    int min_cnt = 0x3f3f3f3f, ans;
    for (int k = 1; k <= n; k++) {
        memset(d, 0, sizeof(d));
        int cnt = 0, flag = 1, b = 0;
        for (int i = 1; i <= n; i++) {
            b ^= d[i];
            if (!a[i] ^ b) {
                if (i + k - 1 > n) {
                    flag = 0;
                    break;
                }
                b ^= 1;
                d[i + k] ^= 1;
                cnt++;
            }
        }
        if (flag) {
            if (cnt < min_cnt) {
                min_cnt = cnt;
                ans = k;
            }
        }
    }
    cout << ans << ' ' << min_cnt << endl;
    return 0;
}
