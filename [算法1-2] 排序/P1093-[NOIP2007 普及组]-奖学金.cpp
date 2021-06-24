// ����˼·
// ʹ�ýṹ��洢ѧ���ĳɼ����ݣ�Ȼ��������ģ��������̼��ɡ�
// ��ѧ�����ܳɼ������ĳɼ�����ͬʱ��Ҫ��������˳������������
// �ṹ������Ҫ����һ����������������Ĵ���

#include <iostream>
#include <algorithm>
using namespace std;

struct Stu {
    int id;  // ѧ�ţ��������
    int chn; // ���ĳɼ�
    int mat; // ��ѧ�ɼ�
    int eng; // Ӣ��ɼ�
    int sum; // �ܳɼ�
};

bool cmp(Stu stu1, Stu stu2) {
    // ���Ȱ��ܳɼ�����
    if (stu1.sum != stu2.sum) return stu1.sum > stu2.sum;
    // �ܳɼ���ͬʱ�������ĳɼ�����
    else if (stu1.chn != stu2.chn) return stu1.chn > stu2.chn;
    // ���ĳɼ�Ҳ��ͬʱ��������˳������
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
