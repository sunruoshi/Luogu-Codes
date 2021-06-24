#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int mat[n][n], temp[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = i * n + j + 1;
        }
    }
    for (int k = 0; k < m; k++) {
        int x, y, r, z;
        cin >> x >> y >> r >> z;
        x--;
        y--;
        for (int i = x - r; i <= x + r; i++) {
            for (int j = y - r; j <= y + r; j++) {
                if (z) {
                    temp[x + y - j][y - x + i] = mat[i][j];
                } else {
                    temp[x - y + j][x + y - i] = mat[i][j];
                }
            }
        }
        for (int i = x - r; i <= x + r; i++) {
            for (int j = y - r; j <= y + r; j++) {
                mat[i][j] = temp[i][j];
            }
        }

    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
