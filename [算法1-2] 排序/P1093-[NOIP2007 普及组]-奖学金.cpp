// 解题思路
// 使用结构体存储学生的成绩数据，然后按照题意模拟排序过程即可。
// 当学生的总成绩和语文成绩都相同时需要按照输入顺序来排序，所以
// 结构体中需要定义一个属性来保存输入的次序。

#include <iostream>
#include <algorithm>
using namespace std;

struct Stu {
    int id;  // 学号（输入次序）
    int chn; // 语文成绩
    int mat; // 数学成绩
    int eng; // 英语成绩
    int sum; // 总成绩
};

bool cmp(Stu stu1, Stu stu2) {
    // 首先按总成绩排序
    if (stu1.sum != stu2.sum) return stu1.sum > stu2.sum;
    // 总成绩相同时，按语文成绩排序
    else if (stu1.chn != stu2.chn) return stu1.chn > stu2.chn;
    // 语文成绩也相同时，按输入顺序排序
    else return stu1.id < stu2.id;
}

int main() {
    int n;
    cin >> n;
    Stu students[n];
    for (int i = 0; i < n; i++) {
        Stu stu;
        cin >> stu.chn >> stu.mat >> stu.eng;
        stu.id = i + 1;
        stu.sum = stu.chn + stu.mat + stu.eng;
        students[i] = stu;
    }
    sort(students, students + n, cmp);
    for (int i = 0; i < 5; i++) {
        cout << students[i].id << " " << students[i].sum << endl;
    }
    return 0;
}
