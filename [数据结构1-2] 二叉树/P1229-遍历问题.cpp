#include <iostream>
#include <string>
using namespace std;

int ans;

int main() {
    string preOrder, postOrder;
    cin >> preOrder >> postOrder;
    for (int i = 0; i < preOrder.size(); i++) {
        for (int j = 1; j < postOrder.size(); j++) {
            if (preOrder[i] == postOrder[j] && preOrder[i + 1] == postOrder[j - 1]) ans++;
        }
    }
    cout << (1 << ans);
    return 0;
}
