#include <iostream>
using namespace std;

typedef long long ll;

ll gcd(ll x, ll y) {
    return x % y ? gcd(y, x % y) : y;
}

ll a, b, c;

int main() {
    cin >> a >> b >> c;
    ll d = a * b / gcd(a, b);
    cout << c * d / gcd(c, d) << endl;
    return 0;
}
