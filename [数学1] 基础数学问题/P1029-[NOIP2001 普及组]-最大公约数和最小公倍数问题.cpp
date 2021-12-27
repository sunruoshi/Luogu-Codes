#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}

int main() {
    int x, y;
    cin >> x >> y;
    int ans = 0;
    for (int i = x; i <= y; i++) {
        if ((x * y) % i == 0 && gcd(i, x * y / i) == x) ans++;
    }
    cout << ans;
    return 0;
}
