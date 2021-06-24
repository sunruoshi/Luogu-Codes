#include <iostream>
#include <string>
using namespace std;

struct Student {
	string name;
	int age;
	int score;
};

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		Student stu;
		cin >> stu.name >> stu.age >> stu.score;
		stu.age++;
		stu.score += stu.score / 5;
		if (stu.score > 600)
			stu.score = 600;
		cout << stu.name << ' ' << stu.age << ' ' << stu.score << endl;
	}
	return 0;
}