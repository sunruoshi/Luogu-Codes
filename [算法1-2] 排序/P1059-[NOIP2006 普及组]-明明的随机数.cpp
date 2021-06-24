#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> rand;
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        rand.insert(d);
    }
    cout << rand.size() << endl;
    set<int>::iterator it;
    for (it = rand.begin(); it != rand.end(); it++) {
        cout << *it << " ";
    }
    return 0;
}
