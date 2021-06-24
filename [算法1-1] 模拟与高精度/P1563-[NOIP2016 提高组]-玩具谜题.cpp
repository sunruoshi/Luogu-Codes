#include <iostream>
#include <string>
using namespace std;

struct Toy {
    int face;
    string name;
};

int main() {
    int n, m, pos = 0;
    cin >> n >> m;
    Toy toys[n];
    for (int   i = 0; i < n; i++) {
        Toy toy;
        cin >> toy.face >> toy.name;
        toys[i] = toy;
    }
    for (int i = 0; i < m; i++) {
        int dir, cnt;
        cin >> dir >> cnt;
        pos = dir ^    toys[pos].face ? (pos + cnt) % n : (pos + n - cnt) % n;
    }
    cout <<    toys[pos].name;
    return 0;
}
