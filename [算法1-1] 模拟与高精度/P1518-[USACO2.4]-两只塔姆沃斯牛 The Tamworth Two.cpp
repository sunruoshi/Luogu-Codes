#include <iostream>
using namespace std;

int state[10][10][10][10][4][4];

int main() {
    char mat[10][10];
    int cx, cy, fx, fy, cd = 0, fd = 0, dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}, t = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 'C') {
                cx = i;
                cy = j;
            } else if (mat[i][j] == 'F') {
                fx = i;
                fy = j;
            }
        }
    }
    while (cx != fx || cy != fy) {
        state[cx][cy][fx][fy][cd % 4][fd % 4] = 1;
        int ncx = cx + dirs[cd % 4][0], ncy = cy + dirs[cd % 4][1], nfx = fx + dirs[fd % 4][0], nfy = fy + dirs[fd % 4][1];
        if (ncx >= 0 && ncx < 10 && ncy >= 0 && ncy < 10 && mat[ncx][ncy] != '*') {
            cx = ncx;
            cy = ncy;
        } else {
            cd++;
        }
        if (nfx >= 0 && nfx < 10 && nfy >= 0 && nfy < 10 && mat[nfx][nfy] != '*') {
            fx = nfx;
            fy = nfy;
        } else {
            fd++;
        }
        if (state[cx][cy][fx][fy][cd % 4][fd % 4]) {
            t = 0;
            break;
        }
        t++;
    }
    cout << t;
    return 0;
}
