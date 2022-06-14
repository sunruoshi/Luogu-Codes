#include <iostream>
using namespace std;

int main() {
    unsigned n;
    cin >> n;
    cout << (((n & 0x0000ffff) << 16) | ((n & 0xffff0000) >> 16)) << endl;
    return 0;
}
