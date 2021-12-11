#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double n, m, t;

bool check(double x) {
    return (pow(1 / (1 + x), t)) >= 1 - n / m * x; 
}

int main() {
    cin >> n >> m >> t;
    double l = 0, r = 5;
    while (r - l >= 0.0001) {
        double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << fixed << setprecision(1) << l * 100;
    return 0;
}
