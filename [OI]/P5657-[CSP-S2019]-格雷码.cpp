#include <iostream>
using namespace std;

int n;
unsigned long long k;

int main() {
    cin >> n >> k;
    k ^= k >> 1;
    while (--n >= 0) cout << ((k >> n) & 1);
    return 0;
}
