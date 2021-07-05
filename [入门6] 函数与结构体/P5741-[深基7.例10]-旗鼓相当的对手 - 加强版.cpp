#include <bits/stdc++.h>
using namespace std;

struct Student {
    string name;
    int s1, s2, s3;
};

int main() {
    int n;
    cin >> n;
    Student students[n];
    for (int i = 0; i < n; i++) {
        Student stu;
        cin >> stu.name >> stu.s1 >> stu.s2 >> stu.s3;
        students[i] = stu;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum1 = students[i].s1 + students[i].s2 + students[i].s3;
            int sum2 = students[j].s1 + students[j].s2 + students[j].s3;
            if (
                    abs(students[i].s1 - students[j].s1) <= 5 &&
                    abs(students[i].s2 - students[j].s2) <= 5 &&
                    abs(students[i].s3 - students[j].s3) <= 5 &&
                    abs(sum1 - sum2) <= 10
               ) {
                cout << students[i].name << ' ' << students[j].name << endl;
            }
        }
    }
    return 0;
}
