#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n], check[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        check[i] = 0;
    }
    for (int i = 0; i < n - 1; i++) {
        int d = abs(arr[i] - arr[i + 1]);
        if (d >= 1 && d <= n - 1) check[d]++;
    }
    for (int i = 1; i < n; i++) {
        if (check[i] == 0) {
            cout << "Not jolly";
            return 0;
        }
    }
    cout << "Jolly";
    return 0;
}
