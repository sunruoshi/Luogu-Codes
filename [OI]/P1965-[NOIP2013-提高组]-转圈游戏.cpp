#include <iostream>
using namespace std;

int n, m, k, x;

int quick_pow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % n;
        a = a * a % n;
        b >>= 1;
    }
    return res;
}

int main() {
    cin >> n >> m >> k >> x;
    cout << (x % n + m % n * quick_pow(10, k) % n) % n << endl;
    return 0;
}
