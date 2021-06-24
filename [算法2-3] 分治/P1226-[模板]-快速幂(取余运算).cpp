#include <iostream>
using namespace std;

long long binpow(long long A, long long P, long long M) {
    if (P == 0) return 0;
    A %= M;
    long long res = 1;
    while (P) {
        if (P & 1) res = res * A % M;
        A = A * A % M;
        P >>= 1;
    }
    return res;
}

int main() {
    long long b, p, k;
    cin >> b >> p >> k;
    cout << b << "^" << p << " mod " << k << "=" << binpow(b, p, k);
    return 0;
}
