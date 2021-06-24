#include <iostream>
#include <string>
using namespace std;

int r, c, k, ans;

int main() {
    int r, c, k;
    cin >> r >> c >> k;
    string mat[r];
    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        mat[i] = s;
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] == '.') {
                if (k == 1) {
                    ans++;
                    continue;
                }
                int n = 1, cnt = 1;
                while (i + n < r && mat[i + n][j] == '.' && cnt < k) {
                    cnt++;
                    n++;
                    if (cnt == k) ans++;
                }
                n = 1, cnt = 1;
                while (j + n < c && mat[i][j + n] == '.' && cnt < k) {
                    cnt++;
                    n++;
                    if (cnt == k) ans++;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
