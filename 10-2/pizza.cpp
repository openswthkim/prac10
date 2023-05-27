/***************************************************************/
/*             HW#7 : ������ �Լ� ���                         */
/*  �ۼ��� : ȫ�浿                    ��¥ : 2023�� 5�� 20��  */
/*                                                             */
/* ���� ���� :    Circle�� ��ӹ��� NamedCircle Ŭ���� �ۼ�    */
/*                ������ ���� ���� ū ���ڸ� ���            */
/***************************************************************/
#include <iostream>
#include <string>
using namespace std;
class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; } // ������ �ʱ�ȭ
	int getRadius() { return radius; } // ������ ����
	void setRadius(int radius) { this->radius = radius; } // �Է� ���� �������� ����
	double getArea() { return 3.14 * radius * radius; } // �������� �̿��� ���� ����
};
class NamedCircle : public Circle { // Circle Ŭ������ ��� ���� Ŭ���� ����
	string name; // �̸� ����
public:
    NamedCircle() : Circle(0) { name = ""; } // �⺻ ������
    NamedCircle(int r, string name) : Circle(r) { this->name = name; } // �������� �̸��� �ʱ�ȭ �ϴ� ������
    string getName() { return name; } // �̸��� ��ȯ
    void setName(string name) { this->name = name; } // �̸��� �����ϴ� �Լ�
};
int main() {
    NamedCircle pizza[5]; // �迭 pizza ����
    string name;
    cout << "5���� ���� �������� ���� �̸��� �Է��ϼ���." << endl;
    for (int i = 0; i < 5; ++i) {
        cout << i + 1 << ">> ";
        int n;
        cin >> n >> name; // �������� �̸� �Է� ����
        pizza[i].setRadius(n); // ������ ����
        pizza[i].setName(name); // �̸� ����
    }
    double max = pizza[0].getArea(); // ���� ū ���� ���� �� ���� ����
    for (int i = 1; i < 5; ++i) {
        if (max < pizza[i].getArea()) { // ���� ������ �ִ� �������� Ŭ ���
            max = pizza[i].getArea(); // �ִ� ������ ���� ���� ����
            name = pizza[i].getName(); // �̸� ����
        }
    }
    cout << "���� ������ ū ���ڴ� " << name << "�Դϴ�." << endl;
}