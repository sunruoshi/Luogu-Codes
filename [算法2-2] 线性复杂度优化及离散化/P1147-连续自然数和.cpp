#include <iostream>
using namespace std;

int main() {
    int m;
    cin >> m;
    int l = 1, r = 2, sum = 3;
    while (l <= m / 2) {
        if (sum < m) {
            sum += ++r;
        } else {
            if (sum == m) cout << l << ' ' << r << endl;
            sum -= l++;
        }
    }
    return 0;
}
