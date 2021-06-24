#include <iostream>
using namespace std;

int main() {
    int n, m;
    long long square = 0, rect = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j) square += (n - i) * (m - j);
            else rect += (n - i) * (m - j);
        }
    }
    cout << square << " " << rect;
    return 0;
}
