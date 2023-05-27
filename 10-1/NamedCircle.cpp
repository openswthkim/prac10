/***************************************************************/
/*             HW#7 : ������ �Լ� ���                         */
/*  �ۼ��� : ȫ�浿                    ��¥ : 2023�� 5�� 20��  */
/*                                                             */
/* ���� ���� :    Circle�� ��ӹ��� NamedCircle Ŭ���� �ۼ�    */
/*                - - - - - - -                                */
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
};
class NamedCircle : public Circle { // Circle Ŭ������ ��� ���� Ŭ���� ����
	string name; // �̸� ����
public:
	NamedCircle(int r, string name) : Circle(r) { this->name = name; } // �������� �̸� �ʱ�ȭ
	void show(){
		cout<<"�������� "<<getRadius() << "�� " << name << endl; // �������� �̸� ���
	}
};
int main() {
	NamedCircle waffle(3, "waffle"); // �������� 3�̰� �̸��� waffle�� ��ü ����
	waffle.show();
}
